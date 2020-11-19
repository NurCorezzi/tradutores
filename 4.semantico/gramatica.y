%code requires {
  #include "node.h"
}

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.tab.h"

#include "type_expression.c"
#include "node.h"
#include "ast.c"
#include "stable.c"

extern char *yytext;
int yylex_destroy ( void );
int yylex();

SymbolNode *symbol_table;
Node *ast;
Scope *global_scope;
int scope_count;
int has_main;

Node* get_params_addv();
Node* get_params_adda();
Node* get_params_graph_call();

void check_graph_call(char *id, Node* graph_params_call);
void check_params(char *function_id, Node *param, Node *param_call);
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *op2);
void check_compare_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2);

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b);
void yyerror (char const *s);
void semantic_error(char const *s);
void warning(char const *s);
int error_recovery_mode;

%}

%define parse.error verbose
%token-table
%locations

%token IF ELSE FOR WHILE 
%token BOOLEAN INT FLOAT GRAPH VOID
%token TO TRUE FALSE
%token ID C_FLOAT C_INT
%token READ WRITE 
%token DFS BFS ADDA ADDV RETURN
%token AND OR LE GE LESS GREATER EQ NE NOT MUL DIV ADD SUB 
%token ASSIGN END OPEN_BRACE CLOSE_BRACE IT SEPARATOR OPEN_P CLOSE_P OPEN_BRACKET CLOSE_BRACKET

%union {
  int id;
  Node* node;
}

%start init

%type<node> BOOLEAN INT FLOAT GRAPH VOID
%type<node> ID C_FLOAT C_INT 

%type<node> init program function params function_call params_call graph_call graph_params_call
%type<node> statements statement
%type<node> statement_no_dangle statement_prefix statement_end dangling_if block

%type<node> expr_relational expr_and expr_or expr_add expr_sub expr_mul expr_div expr_unary
%type<node> unary and or add sub mul div factor
%type<node> compare_op

%type<node> declaration type id dimension access_lvl
%type<node> id_or_access graph_add expr_assign
%type<node> value number number_int number_float boolean_const

%destructor { 
   if ($$ != NULL && strcmp($$->id, "program") != 0) {
    free_tree($$);
  }
} 
init program function params function_call params_call graph_call graph_params_call
statements statement
statement_no_dangle statement_prefix statement_end dangling_if block

expr_relational expr_and expr_or expr_add expr_sub expr_mul expr_div expr_unary
unary and or add sub mul div factor
compare_op

declaration type id dimension access_lvl
id_or_access graph_add expr_assign
value number number_int number_float boolean_const


%%

init: program {
  ast = $$ = $1;

  if (!has_main) {
    warning("no main function identified program will not run");
  }
}
;


/*------------------FUNCTIONS-----------------------*/


program: %empty {$$ = NULL;}
  | program function {
  $$ = create_node("program");
  if ($1 != NULL) {
    Node *it;
    for (it = $1->begin_child; it != NULL; it = it->next) {
      push_child($$, it);
    }
    free_node($1);
  }
  push_child($$, $function);
}
;

function: type dimension id {
  // Necessario declarar funcao na tabela de simbolos antes da declaracao de seus parametros para que escopo esteja correto
  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, $id->complement, STYPE_FUNCTION);
  if (match != NULL && scope_eq(global_scope, match->scope)) {
    char buffer[300] = {0};
    sprintf(buffer, "function \"%s\" already declared", $id->complement);
    semantic_error(buffer);
  }

  if (strcmp($id->complement, "main") == 0) {
    has_main = 1;
  }

  TypeExpression* type = type_build($type, $dimension);
  SymbolNode *entry = stable_create_symbol($id->complement, global_scope, STYPE_FUNCTION, type, NULL);
  symbol_table = stable_add(symbol_table, entry);

  if (!type_can_return(type)) {
    char buffer[300] = {0};
    char *buffer1 = type_to_string(type);
    sprintf(buffer, "type \"%s\" cannot be a return type", buffer1);
    free(buffer1);
    semantic_error(buffer);
  }

  scope_push(&global_scope, &scope_count, entry);
} OPEN_P params CLOSE_P {
  // Obtencao de parametros para symbol table
  SymbolNode *entry = stable_find_with_scope(symbol_table, global_scope, $id->complement, STYPE_FUNCTION);  
  entry->ast_node = $params;
} OPEN_BRACE statements CLOSE_BRACE {
  $$ = create_node("function");

  Node* decl = create_node("declaration");
  push_child(decl, $type);
  if($dimension != NULL) {
    push_child(decl, $dimension);
  }
  push_child(decl, $id);

  Node* block = create_node("block");
  push_child(block, $statements);

  push_child($$, decl);
  push_child($$, $params);
  push_child($$, block);

  scope_pop(&global_scope);
}
| error { error_recovery_mode = 0; $$ = NULL; }
;

params: %empty {$$ = NULL;}
| params SEPARATOR declaration {
  $$ = create_node("params");
  
  Node *it;
  for (it = $1->begin_child; it != NULL; it = it->next) {
    push_child($$, it);
  }
  free_node($1);
  push_child($$, $declaration);
}
| declaration {
  $$ = create_node("params");
  push_child($$, $declaration);
}
;

function_call: id OPEN_P params_call CLOSE_P {
  $$ = create_node("function_call");
  push_child($$, $id);
  push_child($$, $params_call);

  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, $id->complement, STYPE_FUNCTION);

  if (match == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "function \"%s\" not found in scope", $id->complement);
    semantic_error(buffer);
  } else {
    $$->type = type_cpy(match->type);
    check_params(
      match->id,
      match->ast_node ? match->ast_node->begin_child : NULL, 
      $params_call ? $params_call->begin_child : NULL
    );
  } 
}
;

params_call: %empty {$$ = NULL;}
| params_call SEPARATOR expr_assign {
  $$ = create_node("params_call");
  
  Node *it;
  for (it = $1->begin_child; it != NULL; it = it->next) {
    push_child($$, it);
  }
  free_node($1);
  push_child($$, $expr_assign);
} 
| expr_assign {
  $$ = create_node("params_call");
  push_child($$, $expr_assign);
}
;

graph_call: DFS graph_params_call { 
  $$ = create_node("dfs"); 
  push_child($$, $graph_params_call);
  check_graph_call($$->id, $graph_params_call);
}
| BFS graph_params_call { 
  $$ = create_node("bfs"); 
  push_child($$, $graph_params_call);
  check_graph_call($$->id, $graph_params_call);
}
;

graph_params_call: OPEN_P id_or_access SEPARATOR expr_assign[exp1] SEPARATOR expr_assign[exp2] CLOSE_P {
  $$ = create_node("graph_params");
  push_child($$, $id_or_access);
  push_child($$, $exp1);
  push_child($$, $exp2);
}
;


/*------------------STATEMENTS-----------------------*/


statements: %empty {$$ = NULL;} | statements statement {
  $$ = create_node("statements");

  if ($1 != NULL) {
    Node *it;
    for (it = $1->begin_child; it != NULL; it = it->next) {
      push_child($$, it);
    }
    free_node($1);
  }  
  push_child($$, $statement);
}
;

statement: statement_prefix statement_end {
  $$ = $statement_prefix;
  push_child($$, $statement_end);
}
| statement_prefix dangling_if  {
  $$ = $statement_prefix;
  push_child($$, $dangling_if);
}
| statement_end {
  $$ = $1;
}
| dangling_if {
  $$ = $1;
}
| error { error_recovery_mode = 0; $$ = NULL; }
;

statement_no_dangle: statement_prefix statement_end {
  $$ = $statement_prefix;
  push_child($$, $statement_end);
}
| statement_end {
  $$ = $1;
}
;

dangling_if: IF OPEN_P expr_assign CLOSE_P statement {
  $$ = create_node("if_open");
  push_child($$, $expr_assign);
  push_child($$, $statement);
}
;

statement_prefix: IF OPEN_P expr_assign CLOSE_P statement_no_dangle ELSE {
  $$ = create_node("if_else");
  push_child($$, $expr_assign);
  push_child($$, $statement_no_dangle);
} 
| WHILE OPEN_P expr_assign CLOSE_P {
  $$ = create_node("while");
  push_child($$, $expr_assign);
}
| FOR OPEN_P expr_assign[exp1] END expr_assign[exp2] END expr_assign[exp3] CLOSE_P {
  $$ = create_node("for");
  push_child($$, $exp1);
  push_child($$, $exp2);
  push_child($$, $exp3);
}
| FOR OPEN_P id_or_access IT graph_call CLOSE_P {
  $$ = create_node("for_iterator");
  push_child($$, $id_or_access);
  push_child($$, $graph_call);

  if (!type_eq(&TYPE_EXPRESSION_INT, $id_or_access->type)) {
    char buffer[300] = {0};
    sprintf(buffer, "receiving var in for mut be of type int ");
    semantic_error(buffer);
  } 
}
;

block: OPEN_BRACE {  
  scope_push(&global_scope, &scope_count, NULL); 
} statements CLOSE_BRACE {
  $$ = create_node("block");
  push_child($$, $statements);
  scope_pop(&global_scope);
}
;

statement_end: block
| READ id_or_access END {
  $$ = create_node("read");
  push_child($$, $id_or_access);
}
| WRITE expr_assign END {
  $$ = create_node("write");
  push_child($$, $expr_assign);
}
| declaration END {
  $$ = $1;
}
| expr_assign END {
  $$ = $1;
}
| graph_add END{
  $$ = $1;
}
| RETURN expr_assign END {
  $$ = create_node("return");
  push_child($$, $expr_assign);

  Scope* cur = scope_top(global_scope);
  if (cur == NULL || cur->function == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "there is no function for this return statement");
    semantic_error(buffer);
  } else {
    check_assign_expression($$, cur->function->type, $expr_assign);
  }
}
;


/*----------------------EXPRESSIONS--------------------------------*/


expr_assign: expr_relational ASSIGN expr_assign {
  $$ = create_node("expr_assign");
  push_child($$, $1);
  push_child($$, $3);
  check_assign_expression($$, $1->type, $3);

  if ($expr_relational->begin_child->value_type != LVALUE) {
    char buffer[300] = {0};
    sprintf(buffer, "left side on \"ASSIGN\" must be an lvalue");
    semantic_error(buffer);
  }
} 
| expr_relational {  
  $$ = $1;
}
;

expr_relational: expr_and compare_op expr_relational {
  $$ = create_node("expr_relational");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
  check_compare_expression($$, $1, $2, $3);
}
| expr_and 
;

expr_and: expr_or and expr_and {
  $$ = create_node("expr_and");
  push_child($$, $1);
  push_child($$, $3);
  check_boolean_expression($$, $1, $2, $3);

  free_tree($2);
} 
| expr_or
;

expr_or: expr_add or expr_or {
  $$ = create_node("expr_or");
  push_child($$, $1);
  push_child($$, $3);
  check_boolean_expression($$, $1, $2, $3);

  free_tree($2);
} 
| expr_add
;

expr_add: expr_sub add expr_add {
  $$ = create_node("expr_add");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);

  free_tree($2);
} 
| expr_sub
;

expr_sub: expr_mul sub expr_sub {
  $$ = create_node("expr_sub");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);
  
  free_tree($2);
} 
| expr_mul
;

expr_mul: expr_div mul expr_mul {
  $$ = create_node("expr_mul");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);

  free_tree($2);
} 
| expr_div
;

expr_div: expr_unary div expr_div {
  $$ = create_node("expr_div");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);

  free_tree($2);
} 
| expr_unary
;

expr_unary: unary factor {
  $$ = create_node("expr_unary");

  if ($unary == NULL) {
    $$->type = type_cpy($factor->type);
  } else {
    if (type_is_aritmetic($factor->type)) {
      // Gambiarra da preguiça
      if (strcmp($unary->id, "NOT") == 0) {
        $factor->cast = type_get_cast(&TYPE_EXPRESSION_INT, $factor->type);  
        $$->type = type_cpy(&TYPE_EXPRESSION_INT);
      } else {
        $$->type = type_cpy($factor->type);
      }
    } else {
      char buffer[300] = {0};
      sprintf(buffer, "type incompatible with operator \"%s\" ", $unary->id);
      semantic_error(buffer);
    }
  }

  push_child($$, $1);
  push_child($$, $2);
} 
| factor
;

factor: OPEN_P expr_assign CLOSE_P {
  $$ = $expr_assign;
}
| value
| function_call
;


/*-----------------------EXPRESSION SYMBOLS-----------------------------------*/


unary: NOT  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); } 
| add 
| sub  
;

and: AND  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); };
or: OR   { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); };

add: ADD  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); };
sub: SUB  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); };
mul: MUL  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); };
div: DIV  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); };

compare_op: LE  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); }
| GE            { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); }
| LESS          { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); }
| GREATER       { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); }
| EQ            { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); }
| NE            { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); }
;


/*-----------------------MICRO------------------------------*/


graph_add: ADDV OPEN_P id_or_access CLOSE_P { 
  $$ = create_node("adda"); 
  push_child($$, $id_or_access);

  Node* params = get_params_addv();
  check_params(
    $$->id,
    params ? params->begin_child : NULL, 
    $$ ? $$->begin_child : NULL
  );
  free_tree(params);
}
| ADDA OPEN_P id_or_access SEPARATOR expr_assign[exp1] SEPARATOR expr_assign[exp2] CLOSE_P { 
  $$ = create_node("addv"); 
  push_child($$, $id_or_access);
  push_child($$, $exp1);
  push_child($$, $exp2);

  Node* params = get_params_adda();
  check_params(
    $$->id,
    params ? params->begin_child : NULL, 
    $$ ? $$->begin_child : NULL
  );
  free_tree(params);
}
;

declaration: type dimension id {
  $$ = create_node("declaration");
  push_child($$, $type);
  push_child($$, $id);

  if($dimension != NULL) {
    push_child($$, $dimension);
  }

  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, $id->complement, STYPE_VARIABLE);
  if (match != NULL && scope_eq(global_scope, match->scope)) {
    char buffer[300] = {0};
    sprintf(buffer, "variable \"%s\" already declared", $id->complement);
    semantic_error(buffer);
  }

  if ($type->t_token == VOID) {
    char buffer[300] = {0};
    sprintf(buffer, "\"VOID\" cannot be a type");
    semantic_error(buffer);
  }


  TypeExpression* type = type_build($type, $dimension);
  SymbolNode *entry = stable_create_symbol($id->complement, global_scope, STYPE_VARIABLE, type, $$);
  $$->sentry = entry;
  $$->type = type_cpy(type);
  symbol_table = stable_add(symbol_table, entry);
}
;

dimension: %empty {$$ = NULL;}
| OPEN_BRACKET number_int CLOSE_BRACKET {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  $$ = create_node("dimension");
  push_child($$, $number_int);
}
;

value: id_or_access {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
}
| number {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
}
| boolean_const {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
}
;

id_or_access: id access_lvl {
  $$ = create_node("access");
  $$->value_type = LVALUE;
  push_child($$, $id);
  push_child($$, $access_lvl);
    
  SymbolNode *match = stable_find_with_scope(symbol_table, global_scope, $id->complement, STYPE_VARIABLE);

  if (match == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "variable \"%s\" not found in scope", $id->complement);
    semantic_error(buffer);
  } else {
    $$->type = type_from_access_lvl(match->type, $access_lvl);
  
    if ($$->type == NULL) {
      char buffer[300] = {0};
      sprintf(buffer, "access to \"%s\" of incompatible type", $id->complement);
      semantic_error(buffer);    
    }
  }
  $$->sentry = match;
} 
;

access_lvl: %empty {$$ = NULL;}
| OPEN_BRACKET expr_assign CLOSE_BRACKET access_lvl[next_access] {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  $$ = create_node("access_lvl");
  push_child($$, $expr_assign);

  if ($next_access) {
    Node *it;
    for (it = $next_access->begin_child; it != NULL; it = it->next) {
      push_child($$, it);
    }
    free_node($next_access);
  }
}
;

id: ID { 
  $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);
  
  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  $$->complement = cpy;
}
;

type: INT   { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| BOOLEAN   { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| FLOAT     { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| GRAPH     { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| VOID      { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
;

number: number_int | number_float
;

number_int: C_INT {
  $$ = create_node("c_int");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  $$->complement = cpy;
  $$->type = type_base(GTYPE_INT);
}
;

number_float: C_FLOAT {
  $$ = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  $$->complement = cpy;
  $$->type = type_base(GTYPE_FLOAT);
}
;

boolean_const: TRUE { 
  $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  $$->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("1") + 1);
  strcpy(cpy, "1");
  $$->complement = cpy;
  $$->type = type_base(GTYPE_INT);
}
| FALSE             { 
  $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  $$->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("0") + 1);
  strcpy(cpy, "0");
  $$->complement = cpy;
  $$->type = type_base(GTYPE_INT);
}
;

%%

/*-------------------UTILS--------------------------------*/

Node* get_params_addv() {
  Node* params = create_node("standalone_params");

  Node* graph  = create_node("standalone_type"); graph->t_token  = GRAPH; 
  graph->type  = type_build(graph, NULL);

  push_child(params, graph);

  return params;
}

Node* get_params_adda() {
  Node* params = create_node("standalone_params");

  Node* graph  = create_node("standalone_type"); graph->t_token  = GRAPH; 
  Node* v_src  = create_node("standalone_type"); v_src->t_token  = INT; 
  Node* v_dst  = create_node("standalone_type"); v_dst->t_token  = INT; 

  graph->type  = type_build(graph, NULL);
  v_src->type  = type_build(v_src, NULL);
  v_dst->type  = type_build(v_dst, NULL);

  push_child(params, graph);
  push_child(params, v_src);
  push_child(params, v_dst);

  return params;
}


Node* get_params_graph_call() {
  Node* params = create_node("standalone_params");

  Node* graph  = create_node("standalone_type"); graph->t_token  = GRAPH; 
  Node* vertex = create_node("standalone_type"); vertex->t_token = INT; 
  Node* value  = create_node("standalone_type"); value->t_token  = INT; 

  graph->type  = type_build(graph, NULL);
  vertex->type = type_build(vertex, NULL);
  value->type  = type_build(value, NULL);

  push_child(params, graph);
  push_child(params, vertex);
  push_child(params, value);

  return params;
}


/*-------------------TYPE CHECK---------------------------*/

void check_graph_call(char *id, Node* graph_params_call) {
  Node* params = get_params_graph_call();
  check_params(
    id,
    params ? params->begin_child : NULL, 
    graph_params_call ? graph_params_call->begin_child : NULL
  );
  free_tree(params);
}

/**
 * Checa lista de parametros percorrendo sempre next dos nodes passados.
 */
void check_params(char *function_id, Node *param, Node *param_call) {
  if (param == NULL && param_call == NULL) {
    return;
  }
  TypeExpression *param_type = param ? param->type : NULL;
  TypeExpression *param_call_type = param_call ? param_call->type : NULL;

  TypeExpression *tmax = type_max(param_type, param_call_type);
  if (tmax != NULL) {
      param_call->cast = type_get_cast(param_type, param_call_type);  
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, param_type, param_call_type);
    sprintf(buffer, "%s in call \"%s\"", buffer1, function_id);
    semantic_error(buffer);
  }
  check_params(
    function_id,
    param ? param->next : NULL, 
    param_call ? param_call->next : NULL
  );
}

/**
 * Também usado para checar tipo em return statement.
 */
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *op2) {
  TypeExpression *tmax = type_max(tgt_type, op2->type);
  if (type_can_assign(tgt_type) && tmax) {
      op2->cast = type_get_cast(tgt_type, op2->type);  
      tgt->type = type_cpy(tgt_type);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, tgt_type, op2->type);
    sprintf(buffer, "%s with operator \"ASSIGN/RETURN\"", buffer1);
    semantic_error(buffer);
  }
}

void check_compare_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  if (type_is_aritmetic(tmax)) {
      op1->cast = type_get_cast(tmax, op1->type);  
      op2->cast = type_get_cast(tmax, op2->type);  
      tgt->type = type_cpy(&TYPE_EXPRESSION_BOOLEAN);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  // Verifica se realmente pode ocorrer conversao
  tmax = type_max(&TYPE_EXPRESSION_BOOLEAN, tmax);
  if (tmax != NULL) {
      op1->cast = type_get_cast(&TYPE_EXPRESSION_BOOLEAN, op1->type);  
      op2->cast = type_get_cast(&TYPE_EXPRESSION_BOOLEAN, op2->type);  
      tgt->type = type_cpy(&TYPE_EXPRESSION_BOOLEAN);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
  TypeExpression *tmax = type_max(op1->type, op2->type);
  if (type_is_aritmetic(tmax)) {
      op1->cast = type_get_cast(tmax, op1->type);  
      op2->cast = type_get_cast(tmax, op2->type);  
      tgt->type = type_cpy(tmax);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, op1->type, op2->type);
    sprintf(buffer, "%s with operator \"%s\" ", buffer1, operator->id);
    semantic_error(buffer);
  }
}

/*-------------------ERROR/LOG-----------------------------*/

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b) {
  char *undefined = "undefined";
  char *a_str = type_to_string(a);
  char *b_str = type_to_string(b);

  if (a_str == NULL) a_str = undefined;
  if (b_str == NULL) b_str = undefined;

  sprintf(buffer, "incompatible types \"%s\" and \"%s\"", a_str, b_str);

  if (a_str != undefined) free(a_str);
  if (b_str != undefined) free(b_str);
}

void yyerror (char const *s) {
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

void semantic_error(char const *s) {
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m semantic: %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

void warning(char const *s) {
  printf("\033[01;33mwarning\033[0;0m: %s\n", s);
}

int main() {
  scope_push(&global_scope, &scope_count, NULL);
  yyparse();

  printf("\n>>>>>>>>>>AST<<<<<<<<<<<\n\n");
  print_tree(ast, 1);

  printf("\n>>>>>>>>>>SYMBOL TABLE<<<<<<<<<<<\n\n");
  stable_print(symbol_table);
  
  free_scope(global_scope);
  free_tree(ast);
  free_stable(symbol_table);
  yylex_destroy();
}