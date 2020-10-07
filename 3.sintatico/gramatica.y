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

void print_node(Node *node, int depth) {
  int i = 0;
  for(i = 0; i < depth; ++i) printf("  ");
  printf("%s\n", node->id);
}

void print_tree(Node *node, int depth) {
  print_node(node, depth);
  Node *it;
  for (it = node->beginChild; it != NULL; it = it->next) {
    print_tree(it, depth + 1);
  }
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
%type<node> statments statment matched_statment open_statment 
%type<node> while if_else if_no_else
%type<node> declaration type id
%%

init : program {
  root = $$ = $1;
}

/*------------------FUNCOES-----------------------*/


program : %empty {$$ = NULL;}
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

function : type id OPEN_P opt_params CLOSE_P OPEN_BRACE statments CLOSE_BRACE {
  $$ = create_node("function");
  push_child($$, $type);
  push_child($$, $id);
  if ($opt_params != NULL) {
    push_child($$, $opt_params);
  }
  push_child($$, $statments);
}

opt_params : %empty {$$ = NULL;} | params {$$ = $1;}

params : declaration {
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


/*------------------STATMENTS-----------------------*/


statments : %empty {$$ = NULL;}
| statments statment {
  $$ = create_node("statments");
  
  if ($1 != NULL) {
    Node *it;
    for (it = $1->beginChild; it != NULL; it = it->next) {
      push_child($$, it);
    }
  }
  push_child($$, $statment);
}

statment : matched_statment {$$ = $1;}| open_statment {$$ = $1;}

matched_statment : while {$$ = $1;}
| OPEN_BRACE statments CLOSE_BRACE {$$ = $2;}

open_statment : if_no_else | if_else 

if_no_else : IF OPEN_P CLOSE_P statment {
  $$ = create_node("if_no_else");
  push_child($$, $statment);  
}

if_else : IF OPEN_P CLOSE_P matched_statment ELSE open_statment {
  $$ = create_node("if_else");
  push_child($$, $matched_statment);  
  push_child($$, $open_statment);  
}

while : WHILE OPEN_P CLOSE_P statment {
  $$ = create_node("while");
  push_child($$, $statment);  
}


/*----------------------EXPRESSOES--------------------------------*/




/*-----------------------MICRO------------------------------*/



declaration : type id {
  $$ = create_node("declaration");
  push_child($$, $type);
  push_child($$, $id);
}

id : ID { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}

type : INT  { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| BOOLEAN   { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| FLOAT     { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| GRAPH     { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}
| VOID      { $$ = create_node(yytname[YYTRANSLATE(yylval.id)]);}



%%

void yyerror (char const *s) {
  printf ("ERRO: %s\n", s);
}

int main() {
  yyparse();
  print_tree(root, 0);
  // yylex_destroy();
}