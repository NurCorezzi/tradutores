#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "gramatica.tab.h"

SymbolNode *symbol_table;
Node *ast;

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
  char default_format[] = "│%-20p-%-20s│%-15s│%-15s│%-15s│\n";
  char with_child_format[] = "│%-20p┌%-20s│%-15s│%-15s│%-15s│\n";
  char nth_child_format[] = "│%-20p├%-20s│%-15s│%-15s│%-15s│\n";
  char last_child_format[] = "│%-20p└%-20s│%-15s│%-15s│%-15s│\n";
  
  char *format = isChild ? nth_child_format : default_format;

  if (!isChild && entry->matches != NULL) format = with_child_format; 
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