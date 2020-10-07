%{
#include <stdio.h>
#include <stdlib.h>

void yyerror (char const *s);
int yylex();
%}

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
}

%start program

%type<id> NUMBER
%type<id> program
%type<id> bit

%%

program : bit {
  $$ = $1;
  printf("%d\n", $1);
} 

bit : NUMBER NUMBER {
    $$ = 13 + 13;
  } 



%%

void yyerror (char const *s) {
  printf ("ERRO\n");
}

int main() {
  yyparse();
  // yylex_destroy();
}