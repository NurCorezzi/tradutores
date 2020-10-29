%code requires {
  #include "node.h"
}

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.tab.h"

#include "node.h"
#include "ast.c"
#include "stable.c"

extern char *yytext;
int yylex_destroy ( void );
void yyerror (char const *s);
int yylex();
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
%token DFS BFS RETURN
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

%type<node> declaration type id size_specifier
%type<node> declaration_or_assign id_or_access graph_add expr_assign
%type<node> value number number_int number_float boolean_const

%destructor { 
   if (strcmp($$->id, "program") != 0) {
    free_tree($$);
  }
} 
init program function params function_call params_call graph_call graph_params_call
statements statement
statement_no_dangle statement_prefix statement_end dangling_if block

expr_relational expr_and expr_or expr_add expr_sub expr_mul expr_div expr_unary
unary and or add sub mul div factor
compare_op

declaration type id size_specifier
declaration_or_assign id_or_access graph_add expr_assign
value number number_int number_float boolean_const


%%

init: program {
  ast = $$ = $1;
}
;


/*------------------FUNCTIONS-----------------------*/


program: %empty {$$ = NULL;}
  | program function {
  $$ = create_node("program");
  if ($1 != NULL) {
    Node *it;
    for (it = $1->beginChild; it != NULL; it = it->next) {
      push_child($$, it);
    }
    free_node($1);
  }
  push_child($$, $function);
}
;

function: type id OPEN_P params CLOSE_P block {
  $$ = create_node("function");
  push_child($$, $type);
  push_child($$, $id);
  push_child($$, $params);
  push_child($$, $block);

  SymbolNode *entry = stable_create_symbol($id->complement, "NONE", STYPE_FUNCTION, token_to_type($type->t_token), $$);
  $$->sentry = entry;
  symbol_table = stable_add(symbol_table, entry);
}
| error { error_recovery_mode = 0; $$ = NULL; }
;

params: %empty {$$ = NULL;}
|params SEPARATOR declaration {
  $$ = create_node("params");
  
  Node *it;
  for (it = $1->beginChild; it != NULL; it = it->next) {
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
  if ($params_call != NULL) {
    push_child($$, $params_call);
  }
}
;

params_call: %empty {$$ = NULL;}
| params_call SEPARATOR expr_assign {
  $$ = create_node("params_call");
  
  Node *it;
  for (it = $1->beginChild; it != NULL; it = it->next) {
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

graph_call: DFS graph_params_call { $$ = create_node("dfs"); push_child($$, $graph_params_call);}
| BFS  graph_params_call          { $$ = create_node("bfs"); push_child($$, $graph_params_call);}
;

graph_params_call: OPEN_P id SEPARATOR expr_assign[exp1] SEPARATOR expr_assign[exp2] CLOSE_P {
  $$ = create_node("graph_params");
  push_child($$, $id);
  push_child($$, $exp1);
  push_child($$, $exp2);
}
;


/*------------------STATEMENTS-----------------------*/


statements: %empty {$$ = NULL;} | statements statement {
  $$ = create_node("statements");

  if ($1 != NULL) {
    Node *it;
    for (it = $1->beginChild; it != NULL; it = it->next) {
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
| FOR OPEN_P declaration_or_assign END expr_assign[exp1] END expr_assign[exp2] CLOSE_P {
  $$ = create_node("for");
  push_child($$, $declaration_or_assign);
  push_child($$, $exp1);
  push_child($$, $exp2);
}
| FOR OPEN_P declaration IT graph_call CLOSE_P {
  $$ = create_node("for_iterator");
  push_child($$, $declaration);
  push_child($$, $graph_call);
}
;

block: OPEN_BRACE statements CLOSE_BRACE {
  $$ = create_node("block");
  push_child($$, $statements);
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
| declaration_or_assign END {
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
}
;


/*----------------------EXPRESSIONS--------------------------------*/


expr_assign: expr_relational ASSIGN expr_assign {
  $$ = create_node("expr_assign");
  push_child($$, $1);
  push_child($$, $3);
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
}
| expr_and 
;

expr_and: expr_or and expr_and {
  $$ = create_node("expr_and");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
} 
| expr_or
;

expr_or: expr_add or expr_or {
  $$ = create_node("expr_or");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
} 
| expr_add
;

expr_add: expr_sub add expr_add {
  $$ = create_node("expr_add");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
} 
| expr_sub
;

expr_sub: expr_mul sub expr_sub {
  $$ = create_node("expr_sub");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
} 
| expr_mul
;

expr_mul: expr_div mul expr_mul {
  $$ = create_node("expr_mul");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
} 
| expr_div
;

expr_div: expr_unary div expr_div {
  $$ = create_node("expr_div");
  push_child($$, $1);
  push_child($$, $2);
  push_child($$, $3);
} 
| expr_unary
;

expr_unary: unary factor {
  $$ = create_node("expr_unary");
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


graph_add: id OPEN_BRACKET expr_assign[exp1] TO expr_assign[exp2] CLOSE_BRACKET {
  $$ = create_node("graph_add");
  push_child($$, $id);
  push_child($$, $exp1);
  push_child($$, $exp2);
}
;

declaration_or_assign: declaration | declaration ASSIGN expr_assign  {
  $$ = create_node("statements");

  // Divisao em declaracao e atribuicao
  Node* assign = create_node("assignment");
  push_child(assign, create_node($declaration->endChild->id));
  push_child(assign, $expr_assign);

  push_child($$, $declaration);
  push_child($$, assign);
}
;

declaration: type size_specifier id {
  $$ = create_node("declaration");
  push_child($$, $type);
  push_child($$, $id);

  if($size_specifier != NULL) {
    push_child($$, $size_specifier);
  }

  SymbolNode *entry = stable_create_symbol($id->complement, "NONE", STYPE_VARIABLE, token_to_type($type->t_token), $$);
  $$->sentry = entry;
  symbol_table = stable_add(symbol_table, entry);
}
;

size_specifier: %empty {$$ = NULL;}
| OPEN_BRACKET number_int CLOSE_BRACKET {
  $$ = $number_int;
}
;

value: id_or_access {
  $$ = create_node("value");
  push_child($$, $1);
}
| number {
  $$ = create_node("value");
  push_child($$, $1);
}
| boolean_const {
  $$ = create_node("value");
  push_child($$, $1);
}
;

id_or_access: id | id OPEN_BRACKET number_int CLOSE_BRACKET {
  $$ = create_node("access");
  push_child($$, $id);
  push_child($$, $number_int);
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
}
;

number_float: C_FLOAT {
  $$ = create_node("c_float");

  char *cpy = (char*)malloc(strlen(yytext) + 1);
  strcpy(cpy, yytext);
  $$->complement = cpy;
}
;

boolean_const: TRUE { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
| FALSE             { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]); $$->t_token = yylval.id; }
;

%%

void yyerror (char const *s) {
  error_recovery_mode = 1;
  printf("\033[01;33m%d:%d-%d:%d\033[0;0m \033[1;31merror:\033[0;0m %s\n", 
    yylloc.first_line, yylloc.first_column,
    yylloc.last_line, yylloc.last_column,
    s);
}

int main() {
  yyparse();

  printf("\n>>>>>>>>>>AST<<<<<<<<<<<\n\n");
  print_tree(ast, 1);

  printf("\n>>>>>>>>>>SYMBOL TABLE<<<<<<<<<<<\n\n");
  stable_print(symbol_table);
  
  free_tree(ast);
  free_stable(symbol_table);
  yylex_destroy();
}