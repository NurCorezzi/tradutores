#ifndef TYPE_EXPRESSION_H
#define TYPE_EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

GrammarType token_to_type(int token); 

char* gtype_to_string(TypeExpression* type); 
char* type_to_string(TypeExpression* type); 
void type_print(TypeExpression* type); 
void type_print_cast(Cast cast);

TypeExpression* type_array(TypeExpression* type, int size); 

TypeExpression* type_base(GrammarType tbase);
TypeExpression* type_build(Node *type, Node *dimension);

TypeExpression* type_array_cpy(TypeExpression* type);
TypeExpression* type_base_cpy(TypeExpression* type);
TypeExpression* type_cpy(TypeExpression* src); 

TypeExpression* type_from_access_lvl(TypeExpression* tgt, Node *access_lvl);
int type_eq(TypeExpression* a, TypeExpression* b); 

TypeExpression* type_max(TypeExpression* a, TypeExpression* b);
Cast type_get_cast(TypeExpression* tgt, TypeExpression* src); 

int type_is_aritmetic(TypeExpression *type); 
int type_is_boolean(TypeExpression *type); 
int type_can_assign(TypeExpression *tgt); 
int type_can_return(TypeExpression *tgt); 

void free_type(TypeExpression* type);

#endif