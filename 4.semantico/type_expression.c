#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

// typedef struct t_type_expression {
//     int size;
//     struct t_type_expression *child;
//     GrammarType node_type;
// } TypeExpression;

TypeExpression* tarray(TypeExpression* type, int size) {
    TypeExpression* texpr = (TypeExpression*)calloc(1, sizeof(TypeExpression));
    texpr->size = size;
    texpr->child = type;
    texpr->node_type = GTYPE_ARRAY;
    return texpr;
}

TypeExpression* tbase(GrammarType tbase) {
    TypeExpression* texpr = (TypeExpression*)calloc(1, sizeof(TypeExpression));
    texpr->node_type = tbase;
    return texpr;
}