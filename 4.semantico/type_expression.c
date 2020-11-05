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
    case BOOLEAN:  return GTYPE_INT; 
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

void type_print(TypeExpression* type) {
    if (type == NULL) return ;
    char *buffer = type_to_string(type);
    printf("%s", buffer);
    free(buffer);
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
    // Pegar todas as dimensoes
    if (size_specifier) {
        Node *cur = size_specifier->beginChild;
        while(cur != NULL) {
            build = type_array(build, atoi(cur->complement));
            cur = cur->next;
        }
    }
    return build;
}

TypeExpression* type_array_cpy(TypeExpression* type) {
    TypeExpression* texpr = (TypeExpression*)calloc(1, sizeof(TypeExpression));
    texpr->size = type->size;
    texpr->child = type->child;
    texpr->node_type = type->node_type;
    return texpr;
}

TypeExpression* type_base_cpy(TypeExpression* type) {
    TypeExpression* texpr = (TypeExpression*)calloc(1, sizeof(TypeExpression));
    texpr->node_type = type->node_type;
    return texpr;
}

TypeExpression* type_cpy(TypeExpression* src) {
    if (src == NULL) {
        return NULL;
    }

    TypeExpression *cur = src;
    TypeExpression *cpy = NULL;
    TypeExpression *next = NULL;

    while(cur != NULL) {
        TypeExpression *build = NULL;

        switch(cur->node_type) {
            case GTYPE_INT:     build = type_base_cpy(cur); break;  
            case GTYPE_FLOAT:   build = type_base_cpy(cur); break;  
            case GTYPE_GRAPH:   build = type_base_cpy(cur); break;  
            case GTYPE_VOID:    build = type_base_cpy(cur); break;  
            case GTYPE_ARRAY:   build = type_array_cpy(cur); break;
            default: return NULL;
        }

        if (cpy == NULL) {
            cpy = build;
            next = cpy;
        } else {
            next->child = build;
            next = next->child;
        }

        cur = cur->child;
    }
    return cpy;
}

/**
 * Infere o tipo do nivel de acesso. 
 * 
 * @return tipo sendo acessado ou null se acesso é impossivel.
 */
TypeExpression* type_from_access_lvl(TypeExpression* tgt, Node *size_specifier) {
    if (tgt == NULL) {
        return NULL;
    }

    if (size_specifier == NULL) {
        return type_cpy(tgt);
    }

    Node *cur_access = size_specifier->beginChild;
    TypeExpression *cur_type = tgt;
    int matches = 0;

    while(cur_access != NULL) {
        // Caso acesso seja mais profundo do que as dimensoes do tipo
        if (cur_type == NULL) {
            matches = 0;
            break;
        }
        
        // Ainda caso acesso seja mais profundo do que o tipo
        if (cur_type->node_type == GTYPE_ARRAY) {
            matches++;
        } else {
            matches = 0;
            break;    
        }
        cur_access = cur_access->next;
        cur_type = cur_type->child;
    }

    if (matches == 0) {
        return NULL;
    } else {
        while(matches) {
            tgt = tgt->child;
            matches--;
        }

        return type_cpy(tgt);
    }
}

void free_type(TypeExpression* type) {
    if (type == NULL) {
        return;
    }
    free_type(type->child);
    free(type);
}