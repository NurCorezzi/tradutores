#ifndef STABLE_H
#define STABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "scope.h"
#include "code_gen.h"

/*-----------------CONVERSION---------------------*/

char* stype_to_string(int type); 

/*------------PRINT SYMBOL TABLE---------------*/

void stable_symbol_print(SymbolNode* entry, int isChild); 
void stable_print(SymbolNode* table);

/*-------------SYMBOL TABLE--------------*/

SymbolNode* stable_find(SymbolNode* entry, char *id); 
SymbolNode* stable_find_with_scope(SymbolNode* entry, Scope* scope, char *id, SymbolType stype);

SymbolNode* stable_create_symbol(char *id, Scope *scope, SymbolType stype, TypeExpression *type, Node *ast_node);
SymbolNode* stable_add(SymbolNode* table, SymbolNode* entry); 

void free_symbol_node(SymbolNode* node); 
void free_stable(SymbolNode* table); 

#endif