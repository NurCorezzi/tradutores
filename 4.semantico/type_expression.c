#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gramatica.tab.h"
#include "node.h"

// typedef struct t_type_expression {
//     int size;
//     struct t_type_expression *child;
//     GrammarType node_type;
// } TypeExpression;

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

char* gtype_to_string(TypeExpression* type) {
    char buffer[200] = {0};
    
    switch(type->node_type) {
        case GTYPE_BOOLEAN: sprintf(buffer, "%s", "boolean"); break;
        case GTYPE_INT:     sprintf(buffer, "%s", "int"); break;  
        case GTYPE_FLOAT:   sprintf(buffer, "%s", "float"); break;  
        case GTYPE_GRAPH:   sprintf(buffer, "%s", "graph"); break;  
        case GTYPE_VOID:    sprintf(buffer, "%s", "void"); break;  
        case GTYPE_ARRAY:   sprintf(buffer, "[%d]", type->size); break;
        default:            sprintf(buffer, "%s", "NONE");
    }

    return strdup(buffer);
}

char* type_to_string(TypeExpression* type) {
    if (type == NULL) {
        return NULL;
    }

    char buffer[200] = {0};
    TypeExpression* cur = type;
    while(cur != NULL) {
        char* tmp = gtype_to_string(cur);
        strcat(buffer, tmp);
        free(tmp);
        cur = cur->child; 
    }
    return strdup(buffer);
}

TypeExpression* type_array(TypeExpression* type, int size) {
    TypeExpression* texpr = (TypeExpression*)calloc(1, sizeof(TypeExpression));
    texpr->size = size;
    texpr->child = type;
    texpr->node_type = GTYPE_ARRAY;
    return texpr;
}

TypeExpression* type_base(GrammarType tbase) {
    TypeExpression* texpr = (TypeExpression*)calloc(1, sizeof(TypeExpression));
    texpr->node_type = tbase;
    return texpr;
}

TypeExpression* type_build(Node *type, Node *size_specifier) {
    TypeExpression *build = type_base(token_to_type(type->t_token));
    if (size_specifier) {
        build = type_array(build, atoi(size_specifier->complement));
    }
    return build;
}

void free_type(TypeExpression* type) {
    if (type == NULL) {
        return;
    }
    free_type(type->child);
    free(type);
}