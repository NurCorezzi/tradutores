%code requires {
  #include "node.h"
}

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gramatica.tab.h"
#include "node.h"
#include "code_gen.h"
#include "stable.h"
#include "type_expression.h"
#include "ast.h"

extern char *yytext;
int yylex_destroy ( void );
int yylex();

/*----GLOBAL-----*/

extern TypeExpression TYPE_EXPRESSION_VOID;
extern TypeExpression TYPE_EXPRESSION_BOOLEAN;
extern TypeExpression TYPE_EXPRESSION_FLOAT;
extern TypeExpression TYPE_EXPRESSION_INT;

SymbolNode *symbol_table;
Node *ast;

Scope *global_scope;
int scope_count;

Instruction *cgen;
int next_instruction;
int temp_inst_count;
int param_inst_count;
int label_count;
int declaration_count;

int has_main;
int is_declaration_param;

/*-------UTILS-------*/

void normalize_to_list(Node *dst, Node *tree);

Node* get_params_addv();
Node* get_params_adda();
Node* get_params_graph_call();

void check_graph_call(char *id, Node* graph_params_call);
void check_params(char *function_id, Node *param, Node *param_call);
void check_return(Node *tgt, Node *expr);
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *op2);
void check_relational_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_boolean_expression(Node *tgt, Node *op1, Node *operator, Node *op2);
void check_aritmetic_expression(Node *tgt, Node *op1, Node *operator, Node *op2);

void build_incompatible_types_str(char* buffer, TypeExpression *a, TypeExpression *b);
void yyerror (char const *s);
void semantic_error(char const *s);
void warning(char const *s);
int error_recovery_mode;
int invalid;

%}

%define parse.error verbose
%token-table
%locations

%token IF ELSE FOR WHILE 
%token BOOLEAN INT FLOAT GRAPH VOID
%token TRUE FALSE
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
%type<node> statements statement statement_control
%type<node> block

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
statements statement statement_control
block

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
    invalid = 1;
  }
}
;


/*------------------FUNCTIONS-----------------------*/


program: %empty {$$ = NULL;}
  | program function {
    $$ = create_node("program");
  if ($1 != NULL) {
    normalize_to_list($$, $1);
    $$->code = $1->code;
    free_node($1);
  }
  push_child($$, $function);
  
  if ($function != NULL) {
    cgen_append(&($$->code), $function->code);
  } 
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

  is_declaration_param = 1;
  temp_inst_count = 0;
  param_inst_count = 0;

} OPEN_P params CLOSE_P {
  // Obtencao de parametros para symbol table
  SymbolNode *entry = stable_find_with_scope(symbol_table, global_scope, $id->complement, STYPE_FUNCTION);  
  entry->ast_node = $params;
  is_declaration_param = 0;
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

  if (!invalid) {
    if ($params != NULL)      cgen_append(&($$->code), $params->code);
    if ($statements != NULL)  cgen_append(&($$->code), $statements->code);

    // nop para sempre gerar funcao com label inicial caso nao tenha statements, deve ficar antes de return obviamente
    Label *ending = cgen_label_by_counter();
    cgen_append(&($$->code), cgen_instr(ending, TAC_NOP, NULL, NULL, NULL));

    if (strcmp($id->complement, "main") != 0) {
      cgen_append(&($$->code), cgen_instr(NULL, TAC_RETURN, NULL, NULL, NULL));
    }

    if ($statements != NULL) cgen_back_patch($statements->back_patch, ending);

    if ($$->code) {
      char *label_description;
      // Caso seja main nao queremos adicionar "_" na label para que tac possa executar
      if (strcmp($id->complement, "main") == 0) {
        label_description = cgen_label($id->complement, 1)->value;
      } else {
        label_description = cgen_label($id->complement, 0)->value;
      }
     
      if ($$->code->label == NULL) {
        $$->code->label = cgen_label(label_description, 1);
      } else{
        replace_label_value($$->code->label, label_description);  
      }
    }
  }
}
| error { error_recovery_mode = 0; $$ = NULL; }
;

params: %empty {$$ = NULL;}
| params SEPARATOR declaration {
  $$ = create_node("params");
  
  if ($1 != NULL) {
    normalize_to_list($$, $1);
    $$->code = $1->code;
    free_node($1);
  } 
  push_child($$, $declaration);
  cgen_append(&($$->code), $declaration->code);
}
| declaration {
  $$ = create_node("params");
  push_child($$, $declaration);
  cgen_append(&($$->code), $declaration->code);
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

  if (!invalid) {
    cgen_append(
      &($$->code), 
      cgen_function_call(match, $params_call, &temp_inst_count)
    );
  }
}
;

params_call: %empty {$$ = NULL;}
| params_call SEPARATOR expr_assign {
  $$ = create_node("params_call");
  
  if ($1 != NULL) {
    normalize_to_list($$, $1);
    $$->code = $1->code;
    free_node($1);
  } 
  push_child($$, $expr_assign);
  // Parametros nao podem ser juntados aqui pois e necessario last instruction de cada um para acessar o field com seu valor
  // cgen_append(&($$->code), $expr_assign->code);
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
  BackPatchList *back_patch = NULL;

  if ($1 != NULL) {
    normalize_to_list($$, $1);
    $$->code = $1->code;
    back_patch = $1->back_patch;
    free_node($1);
  } 
  push_child($$, $statement);

  if (!invalid) {
    cgen_append(&($$->code), $statement->code);
    if (back_patch && $statement->code->label == NULL) {
      $statement->code->label = cgen_label_by_counter();
    }
    cgen_back_patch(back_patch, $statement->code->label);  
    $$->back_patch = $statement->back_patch;
  }
}
;

block: OPEN_BRACE {  
  scope_push(&global_scope, &scope_count, NULL); 
} statements CLOSE_BRACE {
  $$ = create_node("block");
  if ($statements) {
    $$->code = $statements->code;
    $$->back_patch = $statements->back_patch;
    push_child($$, $statements);
  }
  scope_pop(&global_scope);
}
;

statement_control: block
| IF OPEN_P expr_assign CLOSE_P block {
  $$ = create_node("if_open");
  push_child($$, $expr_assign);
  push_child($$, $block);

  if (!invalid) {
    cgen_append(
      &($$->code),
      cgen_if($$, $expr_assign->code, $block, &temp_inst_count)
    );
  }
}
| IF OPEN_P expr_assign CLOSE_P block[body_if] ELSE statement_control[else_statement] {
  $$ = create_node("if_else");
  push_child($$, $expr_assign);
  push_child($$, $body_if);
  push_child($$, $else_statement);

  if (!invalid) {
    cgen_append(
      &($$->code),
      cgen_if_else($$, $expr_assign->code, $body_if, $else_statement, &temp_inst_count)
    );
  }
} 
;

statement: WHILE OPEN_P expr_assign CLOSE_P block {
  $$ = create_node("while");
  push_child($$, $expr_assign);
  push_child($$, $block);

  if (!invalid) {
    cgen_append(
      &($$->code),
      cgen_while($$, $expr_assign->code, $block, &temp_inst_count)
    );
  }
}
| FOR OPEN_P expr_assign[exp1] END expr_assign[exp2] END expr_assign[exp3] CLOSE_P block {
  $$ = create_node("for");
  push_child($$, $exp1);
  push_child($$, $exp2);
  push_child($$, $exp3);
  push_child($$, $block);

  if (!invalid) {
    cgen_append(
      &($$->code),
      cgen_for($$, $exp1->code, $exp2->code, $exp3->code, $block, &temp_inst_count)
    );
  }
}
| FOR OPEN_P id_or_access IT graph_call CLOSE_P block {
  $$ = create_node("for_iterator");
  push_child($$, $id_or_access);
  push_child($$, $graph_call);
  push_child($$, $block);

  if (!type_eq(&TYPE_EXPRESSION_INT, $id_or_access->type)) {
    char buffer[300] = {0};
    sprintf(buffer, "receiving var in for mut be of type int ");
    semantic_error(buffer);
  } 
}
| READ id_or_access END {
  $$ = create_node("read");
  push_child($$, $id_or_access);

  if (!type_can_read($id_or_access->type)) {
    char buffer[300] = {0};
    char *t_str = type_to_string($id_or_access->type);
    sprintf(buffer, "type %s cannot be read", t_str);
    semantic_error(buffer);
    free(t_str);
  }

  if (!invalid) {
    cgen_append(&($$->code), $id_or_access->code);  
    cgen_append(&($$->code), cgen_read($id_or_access, &temp_inst_count));
  }
}
| WRITE expr_assign END {
  $$ = create_node("write");
  push_child($$, $expr_assign);

  if (!invalid) {
    cgen_append(&($$->code), $expr_assign->code);  
    cgen_append(&($$->code), cgen_write($expr_assign->type, $expr_assign->code, &temp_inst_count));
    cgen_append(&($$->code), cgen_write_string("\n"));          
  }
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
  check_return($$, $expr_assign);

  if (!invalid) {
    cgen_append(&($$->code), cgen_return($expr_assign, &temp_inst_count));
  }
}
| RETURN END {
  $$ = create_node("return");
  check_return($$, NULL);

  if (!invalid) {
    cgen_append(&($$->code), cgen_return(NULL, &temp_inst_count));
  }
}
| statement_control
;

/*----------------------EXPRESSIONS--------------------------------*/


expr_assign: expr_or ASSIGN expr_assign {
  $$ = create_node("expr_assign");
  $$->value_type = LVALUE;
  push_child($$, $1);
  push_child($$, $3);
  check_assign_expression($$, $1->type, $3);

  if ($expr_or->begin_child->value_type != LVALUE) {
    char buffer[300] = {0};
    sprintf(buffer, "left side on \"ASSIGN\" must be an lvalue");
    semantic_error(buffer);
  }

  if (!invalid) {
    cgen_append(&($$->code), cgen_assign($1, $3, &temp_inst_count));
  }
} 
| expr_or {  
  $$ = $1;
}
;

expr_or: expr_or or expr_and {
  $$ = create_node("expr_or");
  push_child($$, $1);
  push_child($$, $3);
  check_boolean_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_boolean($1, $3, TAC_OR, &temp_inst_count));

  free_tree($2);
} 
| expr_and
;

expr_and: expr_and and expr_relational {
  $$ = create_node("expr_and");
  push_child($$, $1);
  push_child($$, $3);
  check_boolean_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_boolean($1, $3, TAC_AND, &temp_inst_count));

  free_tree($2);
} 
| expr_relational
;

expr_relational: expr_relational compare_op expr_add {
  $$ = create_node("expr_relational");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
  check_relational_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_relational($1, $3, $2->t_token, &temp_inst_count));
}
| expr_add 
;

expr_add: expr_add add expr_sub {
  $$ = create_node("expr_add");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_aritmetic($1, $3, TAC_ADD, &temp_inst_count));

  free_tree($2);
} 
| expr_sub
;

expr_sub: expr_sub sub expr_mul {
  $$ = create_node("expr_sub");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_aritmetic($1, $3, TAC_SUB, &temp_inst_count));

  free_tree($2);
} 
| expr_mul
;

expr_mul: expr_mul mul expr_div {
  $$ = create_node("expr_mul");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_aritmetic($1, $3, TAC_MUL, &temp_inst_count));

  free_tree($2);
} 
| expr_div
;

expr_div: expr_div div expr_unary {
  $$ = create_node("expr_div");
  push_child($$, $1);
  push_child($$, $3);
  check_aritmetic_expression($$, $1, $2, $3);
  if (!invalid) cgen_append(&($$->code), cgen_expression_aritmetic($1, $3, TAC_DIV, &temp_inst_count));

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

  if (!invalid) {
    cgen_append(&($$->code), cgen_expression_unary($factor, $unary->t_token, &temp_inst_count));
  }
} 
| factor
;

factor: OPEN_P expr_assign CLOSE_P {
  $$ = $expr_assign;
}
| value
;


/*-----------------------EXPRESSION SYMBOLS-----------------------------------*/


unary: NOT  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; } 
| add 
| sub  
;

and: AND  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; };
or: OR    { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; };

add: ADD  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; };
sub: SUB  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; };
mul: MUL  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; };
div: DIV  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; };

compare_op: LE  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| GE            { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| LESS          { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| GREATER       { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| EQ            { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| NE            { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
;


/*-----------------------MICRO------------------------------*/


graph_add: ADDV OPEN_P id_or_access CLOSE_P { 
  $$ = create_node("addv"); 
  push_child($$, $id_or_access);

  Node* params = get_params_addv();
  check_params(
    $$->id,
    params ? params->begin_child : NULL, 
    $$ ? $$->begin_child : NULL
  );
  free_tree(params);

  if (!invalid) {
    cgen_append(&($$->code), $id_or_access->code);
    cgen_append(
      &($$->code),
      cgen_addv($id_or_access->code, &temp_inst_count)
    );
  }
}
| ADDA OPEN_P id_or_access SEPARATOR expr_assign[exp1] SEPARATOR expr_assign[exp2] CLOSE_P { 
  $$ = create_node("adda"); 
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

  if (!invalid) {
    cgen_append(&($exp1->code), cgen_derref_lvalue(cgen_last_inst($exp1->code)->fields[0], &temp_inst_count));
    cgen_append(&($exp1->code), cgen_cast(cgen_last_inst($exp1->code)->fields[0], $exp1->cast, &temp_inst_count));

    cgen_append(&($exp2->code), cgen_derref_lvalue(cgen_last_inst($exp2->code)->fields[0], &temp_inst_count));
    cgen_append(&($exp2->code), cgen_cast(cgen_last_inst($exp2->code)->fields[0], $exp2->cast, &temp_inst_count));

    Instruction *append = NULL;
    cgen_append(
      &append,
      cgen_adda($id_or_access->code, $exp1->code, $exp2->code, &temp_inst_count)
    );

    cgen_append(&($$->code), $id_or_access->code);
    cgen_append(&($$->code), $exp1->code);
    cgen_append(&($$->code), $exp2->code);
    cgen_append(&($$->code), append);
  }
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
  if (type && $dimension && type->size == 0) {
    char buffer[300] = {0};
    sprintf(buffer, "variable \"%s\" should not be a zero sized array", $id->complement);
    semantic_error(buffer);  
  }

  SymbolNode *entry = stable_create_symbol($id->complement, global_scope, STYPE_VARIABLE, type, $$);
  $$->sentry = entry;
  $$->type = type_cpy(type);
  symbol_table = stable_add(symbol_table, entry);

  if (!invalid) {
    if ($dimension != NULL) {
      // A principio nao esta sendo utilizado mas e gerado caso seja necessario
      // cgen_append(&($$->code), $dimension->code);
    }

    if (is_declaration_param) { 
      cgen_append(
        &($$->code),
        cgen_declaration_param(entry, &param_inst_count)
      );
    } else {
      cgen_append(
        &($$->code),
        cgen_declaration(entry, &temp_inst_count)
      );
    }
  }
}
;

dimension: %empty {$$ = NULL;}
| OPEN_BRACKET number_int CLOSE_BRACKET {
  // OBS: SE EM ALGUM MOMENTO MAIS DIMENSOES FOREM ADICIONADAS COLOCAR EM BEGIN/END CHILD
  $$ = create_node("dimension");
  push_child($$, $number_int);
  $$->code = $number_int->code;
}
;

value: id_or_access {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
  $$->code = $1->code;
  $$->value_type = $1->value_type;
}
| number {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
  $$->code = $1->code;
}
| boolean_const {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
  $$->code = $1->code;
}
| function_call {
  $$ = create_node_with_type("value", $1->type);
  push_child($$, $1);
  $$->code = $1->code;
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

    if (!invalid) {
      Node *access = $access_lvl == NULL ? NULL : $access_lvl->begin_child;
      cgen_append(
        &($$->code),
        cgen_var_access(match, access, &temp_inst_count)
      );
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
    normalize_to_list($$, $next_access);
    free_node($next_access);
  }

  TypeExpression *tmax = type_max(&TYPE_EXPRESSION_INT, $expr_assign->type);
  $expr_assign->cast = type_get_cast(&TYPE_EXPRESSION_INT, $expr_assign->type);
  if (tmax == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "access must be of type int ");
    semantic_error(buffer);
  }

  if (!invalid) {
    cgen_append(&($expr_assign->code), cgen_derref_lvalue(cgen_last_inst($expr_assign->code)->fields[0], &temp_inst_count));
    cgen_append(&($expr_assign->code), cgen_cast(cgen_last_inst($expr_assign->code)->fields[0], $expr_assign->cast, &temp_inst_count));
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
  
  if (!invalid) {
    cgen_append(&($$->code), cgen_const_code(TAC_OPTYPE_INT, atoi($$->complement), 0.0, &temp_inst_count));
  }
}
;

number_float: C_FLOAT {
  $$ = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  $$->complement = cpy;
  $$->type = type_base(GTYPE_FLOAT);
  
  if (!invalid) {
    cgen_append(&($$->code), cgen_const_code(TAC_OPTYPE_FLOAT, 0, atof($$->complement), &temp_inst_count));
  }
}
;

boolean_const: TRUE { 
  $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  $$->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("1") + 1);
  strcpy(cpy, "1");
  $$->complement = cpy;
  $$->type = type_base(GTYPE_INT);
  
  if (!invalid) {
    cgen_append(&($$->code), cgen_const_code(TAC_OPTYPE_INT, 1, 0, &temp_inst_count));
  }
}
| FALSE             { 
  $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); 
  $$->t_token = yylval.id; 
  char *cpy = (char*)malloc(strlen("0") + 1);
  strcpy(cpy, "0");
  $$->complement = cpy;
  $$->type = type_base(GTYPE_INT);
  
  if (!invalid) {
    cgen_append(&($$->code), cgen_const_code(TAC_OPTYPE_INT, 0, 0, &temp_inst_count));
  }
}
;

%%

/*-------------------UTILS--------------------------------*/

void normalize_to_list(Node *dst, Node *tree) {
  if (dst == NULL || tree == NULL) {
    return;
  }

  Node *it = tree->begin_child;
  while (it != NULL) {
    Node *tmp = it->next;
    push_child(dst, it);
    it = tmp;
  }
}

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

void check_return(Node *tgt, Node *expr) {
  Scope* cur = scope_top(global_scope);
  if (cur == NULL || cur->function == NULL) {
    char buffer[300] = {0};
    sprintf(buffer, "there is no function for this return statement");
    semantic_error(buffer);
  } else {
    check_assign_expression(tgt, cur->function->type, expr);
  }
}

/**
 * Também usado para checar tipo em return statement.
 */
void check_assign_expression(Node *tgt, TypeExpression *tgt_type, Node *src) {
  TypeExpression *src_type = src ? src->type : &TYPE_EXPRESSION_VOID;
  TypeExpression *tmax = type_max(tgt_type, src_type);
  if (type_can_assign(tgt_type) && tmax) {
    if (src) {
      src->cast = type_get_cast(tgt_type, src_type);  
    }
    tgt->type = type_cpy(tgt_type);
  } else {
    char buffer[400] = {0}, buffer1[300] = {0};
    build_incompatible_types_str(buffer1, tgt_type, src_type);
    sprintf(buffer, "%s with operator \"ASSIGN/RETURN\"", buffer1);
    semantic_error(buffer);
  }
}

void check_relational_expression(Node *tgt, Node *op1, Node *operator, Node *op2) {
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
  invalid = 1;
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

void semantic_error(char const *s) {
  invalid = 1;
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

  if (!invalid && ast) {
    printf("\n>>>>>>>>>>TAC<<<<<<<<<<< (EM ARQUIVO \"out.tac\")\n\n");
    print_code(ast->code);

    fflush(stdout);
    FILE* tac_f = freopen("out.tac", "w", stdout);
    print_code(ast->code);
    fclose(tac_f);
  }
  
  free_scope(global_scope);
  free_tree(ast);
  free_stable(symbol_table);
  free_cgen();

  yylex_destroy();

  return 0;
}