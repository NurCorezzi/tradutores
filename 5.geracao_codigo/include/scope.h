#ifndef SCOPE_H
#define SCOPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

int scope_sz(Scope* a);
int scope_access_rank(Scope* a, Scope *b); 
int scope_eq(Scope* a, Scope *b); 

Scope* scope_create(int id); 
Scope* cpy_scope(Scope* scope); 

char* scope_to_string(Scope* scope); 
void print_scope(Scope* scope);

void free_node_scope(Scope* scope); 
void free_scope(Scope* scope); 

void scope_push(Scope **global_scope, int *scope_count, SymbolNode *function);
void scope_pop(Scope **global_scope);
Scope* scope_top(Scope *global_scope); 

#endif
