%code requires {
  #include "node.h"
}

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

void yyerror (char const *s);
int yylex();

Node *root;
void (*tree_prefix[150]) (void);
int i_prefix = 0;

Node* create_node(char const *id) {
  Node* node = (Node*)calloc(1, sizeof(Node));
  
  char* cpy = (char*)malloc(strlen(id) + 1);
  strcpy(cpy, id);
  node->id = cpy;
  
  return node;
}

void push_child(Node *root, Node *child) {
  if (root->beginChild == NULL) {
    root->beginChild = child;
    root->endChild = child;
  } else {
    root->endChild->next = child;
    root->endChild = child;
  }
}

void print_l_end() {printf("└");}
void print_l_middle() {printf("├");}
void print_horizontal() {printf("─");}
void print_vertical() {printf("│");}
void print_space() {printf(" ");}

void print_prefix() {
  int i;
  for (i = 0; i < i_prefix; ++i) {
    (*tree_prefix[i])();
  }
}

void print_node(Node *node, int isLast) {
  tree_prefix[i_prefix-1] = &print_space;
  if (isLast) {
    tree_prefix[i_prefix-3] = &print_l_end;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_prefix();
    printf("%s\n", node->id);
    tree_prefix[i_prefix-3] = &print_space;
    tree_prefix[i_prefix-2] = &print_space;
  } else {
    tree_prefix[i_prefix-3] = &print_l_middle;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_prefix();
    printf("%s\n", node->id);
    tree_prefix[i_prefix-3] = &print_vertical;
    tree_prefix[i_prefix-2] = &print_space;
  }  
}

void print_tree(Node *node, int isLast) {
  i_prefix += 3;
  print_node(node, isLast);  
  Node *it;

  for (it = node->beginChild; it != NULL; it = it->next) {
    print_tree(it, it == node->endChild);
  }
  i_prefix -= 3;
}

%}

%define parse.error verbose
%token-table

%token IF ELSE FOR WHILE 
%token BOOLEAN INT FLOAT GRAPH VOID
%token TO TRUE FALSE
%token ID NUMBER 
%token READ WRITE 
%token DFS BFS RETURN
%token AND OR LE GE LESS GREATER EQ NE NOT MUL DIV SUM SUB 
%token ASSIGN END OPEN_BRACE CLOSE_BRACE IT SEPARATOR OPEN_P CLOSE_P OPEN_BRACKET CLOSE_BRACKET

%union {
  int id;
  Node* node;
}

%start init

%type<node> BOOLEAN INT FLOAT GRAPH VOID
%type<node> ID NUMBER 

%type<node> init program function opt_params params
%type<node> statments statment
%type<node> declaration type id

%type<node> statment_no_dangle statment_prefix statment_end dangling_if
%type<node> declaration_or_assign id_or_access expr_relational factor expr_assign

%%

init: program {
  root = $$ = $1;
}
;

/*------------------FUNCOES-----------------------*/

program: %empty {$$ = NULL;}
  | program function {
  $$ = create_node("program");
  if ($1 != NULL) {
    Node *it;
    for (it = $1->beginChild; it != NULL; it = it->next) {
      push_child($$, it);
    }
  }
  push_child($$, $function);
}
;

function: type id OPEN_P opt_params CLOSE_P OPEN_BRACE statments CLOSE_BRACE {
  $$ = create_node("function");
  push_child($$, $type);
  push_child($$, $id);
  if ($opt_params != NULL) {
    push_child($$, $opt_params);
  }
  push_child($$, $statments);
}
;

opt_params: %empty {$$ = NULL;} | params {$$ = $1;}
;

params: declaration {
  $$ = create_node("params");
  push_child($$, $declaration);
}
| params SEPARATOR declaration {
  $$ = create_node("params");
  
  Node *it;
  for (it = $1->beginChild; it != NULL; it = it->next) {
    push_child($$, it);
  }
  push_child($$, $declaration);
}
;

/*------------------STATMENTS-----------------------*/

statments: %empty {$$ = NULL;} | statments statment {
  $$ = create_node("statments");

  if ($1 != NULL) {
    Node *it;
    for (it = $1->beginChild; it != NULL; it = it->next) {
      push_child($$, it);
    }
  }  
  push_child($$, $statment);
}
;

statment: statment_prefix statment_end {
  $$ = $statment_prefix;
  push_child($$, $statment_end);
}
| statment_prefix dangling_if  {
  $$ = $statment_prefix;
  push_child($$, $dangling_if);
}
| statment_end {
  $$ = $1;
}
| dangling_if {
  $$ = $1;
}
;

statment_no_dangle: statment_prefix statment_end {
  $$ = $statment_prefix;
  push_child($$, $statment_end);
}
| statment_end {
  $$ = $1;
}
;

dangling_if: IF OPEN_P expr_assign CLOSE_P statment {
  $$ = create_node("if_open");
  push_child($$, $expr_assign);
  push_child($$, $statment);
}
;

statment_prefix: IF OPEN_P expr_assign CLOSE_P statment_no_dangle ELSE {
  $$ = create_node("if_else");
  push_child($$, $expr_assign);
  push_child($$, $statment_no_dangle);
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
;

statment_end: OPEN_BRACE statments CLOSE_BRACE {
  $$ = create_node("block");
  if ($statments != NULL) {
    Node *it;
    for (it = $statments->beginChild; it != NULL; it = it->next) {
      push_child($$, it);
    }
  }  
}
| READ END {
  $$ = create_node("read");
}
| WRITE END {
  $$ = create_node("write");
}
| declaration_or_assign END {
  $$ = $1;
}
;


/*----------------------EXPRESSOES--------------------------------*/

expr_assign: id_or_access ASSIGN expr_relational {
  $$ = create_node("assignment");
  push_child($$, $id_or_access);
  push_child($$, $expr_relational);
} 
| expr_relational {  
  $$ = $1;
}
;

expr_relational: factor {
  $$ = create_node("expr_relational");
  push_child($$, $factor);
}
;

factor: OPEN_P expr_assign CLOSE_P {
  $$ = $expr_assign;
}
| id
;

/*-----------------------MICRO------------------------------*/

declaration_or_assign: declaration | declaration ASSIGN expr_assign  {
  $$ = create_node("statments");

  // Divisao em declaracao e atribuicao
  Node* assign = create_node("assignment");
  push_child(assign, create_node($declaration->endChild->id));
  push_child(assign, $expr_assign);

  push_child($$, $declaration);
  push_child($$, assign);
}
;

declaration: type id {
  $$ = create_node("declaration");
  push_child($$, $type);
  push_child($$, $id);
}
;

id_or_access: id
;

id: ID { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
;

type: INT  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| BOOLEAN   { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| FLOAT     { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| GRAPH     { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| VOID      { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
;


%%

void yyerror (char const *s) {
  printf ("ERRO: %s\n", s);
}

int main() {
  yyparse();
  print_tree(root, 1);
  // yylex_destroy();
}