#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "gramatica.tab.h"
#include "scope.h"

/*--------------------ESCOPO---------------------*/


int scope_sz(Scope* a) {
  if (a == NULL) {
    return 0;
  }
  return scope_sz(a->child) + 1;
}

/**
 * Determina acessibilidade de 'a' por 'b', quanto maior valor melhor o match.
 */
int scope_access_rank(Scope* a, Scope *b) {
  if (a == NULL || b == NULL) {
    return a == b;
  }

  int matches = 0;
  while(a != NULL && b != NULL) {
    if (a->id != b->id) return -1;
    matches++;
    a = a->child;
    b = b->child;
  }

  if (a != NULL && b == NULL) {
    return -1;
  }
  return matches;
}

/**
 * Determina equivalencia de escopos, true or false. 
 */
int scope_eq(Scope* a, Scope *b) {
  int rank = scope_access_rank(a, b);
  return rank == scope_sz(b);
}


Scope* scope_create(int id) {
  Scope* scope = (Scope*)calloc(1, sizeof(Scope));
  scope->id = id;
  return scope;
}

Scope* cpy_scope(Scope* scope) {
  if (scope == NULL) {
    return NULL;
  }

  Scope* base = scope_create(scope->id);
  scope = scope->child;
  Scope* cur = base;
  while(scope != NULL) {
    cur->child = scope_create(scope->id);
    cur = cur->child;
    scope = scope->child;
  }
  return base;
}

char* scope_to_string(Scope* scope) {
  if (scope == NULL) {
    return NULL;
  }
  char buffer[100] = {0};
  Scope *cur = scope;
  while(cur != NULL) {
    char buffer_int[20] = {0};
    sprintf(buffer_int, "%d{", cur->id);
    strcat(buffer, buffer_int);
    cur = cur->child;
  }

  return strdup(buffer);
}

void print_scope(Scope* scope) {
  if (scope == NULL) {
    return;
  }
  Scope *cur = scope;
  while(cur != NULL) {
    printf("%d#", cur->id);
    cur = cur->child;
  }
  printf("\n");
}

void free_node_scope(Scope* scope) {
  free(scope);
}

void free_scope(Scope* scope) {
  if (scope == NULL) {
    return;
  }
  free_scope(scope->child);
  free_node_scope(scope);
}

void scope_push(Scope **global_scope, int *scope_count, SymbolNode *function) {
  Scope** base = global_scope;
  Scope *child = scope_create((*scope_count)++);
  child->function = function;
  if ((*base) == NULL) {
    (*base) = child;
    return;
  }
  Scope *cur = *base;
  while(cur->child != NULL) {
    cur = cur->child;
  }
  // Propagar funcao atual nos novos escopos
  if (function == NULL) {
    child->function = cur->function;
  }
  cur->child = child;
}

void scope_pop(Scope **global_scope) {
  Scope** base = global_scope;
  if ((*base) == NULL) {
    return;
  }
  Scope *past = NULL;
  Scope *cur = *base;
  while(cur->child != NULL) {
    past = cur;
    cur = cur->child;
  }
  free_scope(cur);

  if (past == NULL) {
    (*base) = NULL;
  } else {
    past->child = NULL;
  }
}

Scope* scope_top(Scope *global_scope) {
  Scope* base = global_scope;
  if (base == NULL) {
    return NULL;
  }
  while(base->child != NULL) {
    base = base->child;
  }
  return base;
}
