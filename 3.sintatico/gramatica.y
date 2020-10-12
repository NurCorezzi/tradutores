%code requires {
  #include "node.h"
}

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gramatica.tab.h"

#include "node.h"

extern char *yytext;
int yylex_destroy ( void );
void yyerror (char const *s);
int yylex();
int error_recovery_mode;

SymbolNode *symbol_table;
Node *ast;

/*-------------AST-------------------*/

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
  if (child == NULL) {
    return;
  }

  if (root->beginChild == NULL) {
    root->beginChild = child;
    root->endChild = child;
  } else {
    root->endChild->next = child;
    root->endChild = child;
  }
}

void free_node(Node *node) {
  if (node->id != NULL) free(node->id);
  if (node->complement != NULL) free(node->complement);
  free(node);
}

void free_tree(Node *root) {
  if (root == NULL) return;

  Node *it = root->beginChild;
  while (it != NULL) {
    Node *next = it->next;
    free_tree(it);
    it = next;
  }
  free_node(root);
}

/*-----------------CONVERSION---------------------*/

GrammarType token_to_type(int token) {
  switch(token) {
    case BOOLEAN:  return GTYPE_BOOLEAN; 
    case INT:      return GTYPE_INT; 
    case FLOAT:    return GTYPE_FLOAT; 
    case GRAPH:    return GTYPE_GRAPH; 
    case VOID:     return GTYPE_VOID; 
    default:       return -1;
  }
}

char* stype_to_string(int type) {
  switch(type) {
    case STYPE_FUNCTION:  return "function";
    case STYPE_VARIABLE:  return "variable";
    default:              return "NONE";
  }
}

char* gtype_to_string(int type) {
  switch(type) {
    case GTYPE_BOOLEAN: return "boolean";
    case GTYPE_INT:     return "int";
    case GTYPE_FLOAT:   return "float";
    case GTYPE_GRAPH:   return "graph";
    case GTYPE_VOID:    return "void";
    default:            return "NONE";
  }
}

/*------------PRINT SYMBOL TABLE---------------*/

void stable_symbol_print(SymbolNode* entry, int isChild) {
  char default_format[] = "│%-20p├%-20s│%-15s│%-15s│%-15s│\n";
  char nth_child_format[] = " %-20p├%-20s %-15s %-15s %-15s \n";
  char last_child_format[] = " %-20p└%-20s %-15s %-15s %-15s \n";
  
  char *format = isChild ? nth_child_format : default_format;
  if (isChild && entry->matches == NULL) format = last_child_format;

  printf(format, 
    entry, 
    entry->id, 
    entry->scope, 
    stype_to_string(entry->stype), 
    gtype_to_string(entry->gtype)
  );
}

void stable_print(SymbolNode* table) {
  printf("│%-20s│%-20s│%-15s│%-15s│%-15s│\n", "ID", "ENTRY", "SCOPE", "STYPE", "GTYPE");

  SymbolNode *entry = table;
  while(entry) {
    stable_symbol_print(entry, 0);
    
    SymbolNode *match = entry->matches;
    while(match) {
      stable_symbol_print(match, 1);
      match = match->matches;
    }    
    
    entry = entry->next;
  }
}

/*-------------SYMBOL TABLE--------------*/


SymbolNode* stable_create_symbol(char *id, char *scope, SymbolType stype, GrammarType gtype, Node *ast_node) {
  SymbolNode* symbol = (SymbolNode*)calloc(1, sizeof(SymbolNode));
  char *cpy;

  cpy = (char*)malloc(strlen(id) + 1);
  strcpy(cpy, id);
  symbol->id = cpy;

  cpy = (char*)malloc(strlen(scope) + 1);
  strcpy(cpy, scope);
  symbol->scope = cpy;

  symbol->stype = stype;
  symbol->gtype = gtype;
  symbol->ast_node = ast_node;

  return symbol;
}

SymbolNode* stable_find(SymbolNode* entry, char *id) {
  if (entry == NULL) return NULL;
  if (strcmp(id, entry->id) == 0) return entry;
  else return stable_find(entry->next, id);
}

SymbolNode* stable_add(SymbolNode* table, SymbolNode* entry) {
  SymbolNode* lastSymbol = table;
  while(lastSymbol && lastSymbol->next != NULL) {
    lastSymbol = lastSymbol->next;
  }

  if (lastSymbol == NULL) {
    table = entry;
  } else {
    SymbolNode *match = stable_find(table, entry->id);
    while(match && match->matches != NULL) {
      match = match->matches;
    }

    if (match != NULL) {
      entry->matches = match->matches;
      match->matches = entry;
    } else {
      entry->next = lastSymbol->next;
      lastSymbol->next = entry;  
    }
  }

  return table;
}

void free_symbol_node(SymbolNode* node) {
  if (node->id) free(node->id);
  if (node->scope) free(node->scope);
  free(node);
}

void free_stable(SymbolNode* table) {
  SymbolNode *entry = table;
  SymbolNode *memo;

  while(entry) {    
    SymbolNode *match = entry->matches;
    while(match) {
      memo = match;
      match = match->matches;
      free_symbol_node(memo);
    }    

    memo = entry;    
    entry = entry->next;
    free_symbol_node(memo);
  }
}

/*------------PRINT TREE---------------*/

void print_l_end() {printf("└");}
void print_l_middle() {printf("├");}
void print_horizontal() {printf("─");}
void print_vertical() {printf("│");}
void print_space() {printf(" ");}

void print_node_prefix() {
  int i;
  for (i = 0; i < i_prefix; ++i) {
    (*tree_prefix[i])();
  }
}

void print_node_sufix(Node *node) {
  printf("%s", node->id);
  if (node->complement) printf(": %s", node->complement);
  printf("\n");
}

void print_node(Node *node, int isLast) {
  tree_prefix[i_prefix-1] = &print_space;
  if (isLast) {
    tree_prefix[i_prefix-3] = &print_l_end;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_node_prefix();
    print_node_sufix(node);
    tree_prefix[i_prefix-3] = &print_space;
    tree_prefix[i_prefix-2] = &print_space;
  } else {
    tree_prefix[i_prefix-3] = &print_l_middle;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_node_prefix();
    print_node_sufix(node);
    tree_prefix[i_prefix-3] = &print_vertical;
    tree_prefix[i_prefix-2] = &print_space;
  }  
}

void print_tree(Node *node, int isLast) {
  if (node == NULL) return;

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
%locations

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

%destructor { 
  if (error_recovery_mode) {
    free_tree($$);
  }
} init program function opt_params params statments statment declaration type id statment_no_dangle statment_prefix statment_end dangling_if declaration_or_assign id_or_access expr_relational factor expr_assign

%%

init: program {
  ast = $$ = $1;
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
    free_node($1);
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
| error { error_recovery_mode = 0; $$ = NULL; }
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
  free_node($1);
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
    free_node($1);
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
| error { error_recovery_mode = 0; $$ = NULL; }
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
| FOR OPEN_P declaration IT CLOSE_P {
  $$ = create_node("for_iterator");
  push_child($$, $declaration);
}
;

statment_end: OPEN_BRACE statments CLOSE_BRACE {
  $$ = create_node("block");
  if ($statments != NULL) {
    Node *it;
    for (it = $statments->beginChild; it != NULL; it = it->next) {
      push_child($$, it);
    }
    free_node($statments);
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

  SymbolNode *entry = stable_create_symbol($id->complement, "NONE", STYPE_VARIABLE, token_to_type($type->t_token), $id);
  symbol_table = stable_add(symbol_table, entry);
}
;

id_or_access: id
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