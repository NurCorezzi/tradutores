#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "gramatica.tab.h"
#include "scope.c"
#include "code_gen.h"

/*-----------------CONVERSION---------------------*/

char* stype_to_string(int type) {
  switch(type) {
    case STYPE_FUNCTION:  return "function";
    case STYPE_VARIABLE:  return "variable";
    default:              return "NONE";
  }
}

/*------------PRINT SYMBOL TABLE---------------*/

void stable_symbol_print(SymbolNode* entry, int isChild) {
  char default_format[] = "│%-20p-%-20s│%-15s│%-15s│%-15s│%-15s|\n";
  char with_child_format[] = "│%-20p┌%-20s│%-15s│%-15s│%-15s│%-15s|\n";
  char nth_child_format[] = "│%-20p├%-20s│%-15s│%-15s│%-15s│%-15s|\n";
  char last_child_format[] = "│%-20p└%-20s│%-15s│%-15s│%-15s│%-15s|\n";
  
  char *format = isChild ? nth_child_format : default_format;

  if (!isChild && entry->matches != NULL) format = with_child_format; 
  if (isChild && entry->matches == NULL) format = last_child_format;

  char *field_ref = field_toa(entry->tac_ref);

  printf(format, 
    entry, 
    entry->id, 
    entry->scope_str, 
    stype_to_string(entry->stype), 
    entry->type_str,
    field_ref
  );

  free(field_ref);
}

void stable_print(SymbolNode* table) {
  printf("│%-20s│%-20s│%-15s│%-15s│%-15s│%-15s|\n", "ID", "ENTRY", "SCOPE", "STYPE", "GTYPE", "TAC_FIELD");

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

/**
 * id e scope serão copiados.
 * type e ast_node esperam que tenham sido criados por fora.
 */
SymbolNode* stable_create_symbol(char *id, Scope *scope, SymbolType stype, TypeExpression *type, Node *ast_node) {
  SymbolNode* symbol = (SymbolNode*)calloc(1, sizeof(SymbolNode));
  char *cpy;

  cpy = (char*)malloc(strlen(id) + 1);
  strcpy(cpy, id);
  symbol->id = cpy;
  symbol->scope = cpy_scope(scope);
  symbol->scope_str = scope_to_string(symbol->scope);
  symbol->type_str = type_to_string(type);

  symbol->stype = stype;
  symbol->type = type;
  symbol->ast_node = ast_node;

  return symbol;
}

SymbolNode* stable_find(SymbolNode* entry, char *id) {
  if (entry == NULL) return NULL;
  if (strcmp(id, entry->id) == 0) return entry;
  else return stable_find(entry->next, id);
}

SymbolNode* stable_find_with_scope(SymbolNode* entry, Scope* scope, char *id, SymbolType stype) {
  if (entry == NULL) return NULL;
  SymbolNode* match = NULL;
  SymbolNode* cur = stable_find(entry, id);

  while(cur != NULL) {
    int rank = scope_access_rank(cur->scope, scope);
    int is_match = stype == cur->stype;
    is_match &= rank >= 0;

    if (is_match && (match == NULL || rank > scope_access_rank(match->scope, scope))) {
      match = cur;
    }
    cur = cur->matches;
  }

  return match;
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
  if (node->scope) free_scope(node->scope);
  if (node->scope_str) free(node->scope_str);
  if (node->type) free_type(node->type);
  if (node->type_str) free(node->type_str);
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