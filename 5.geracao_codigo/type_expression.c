#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gramatica.tab.h"
#include "node.h"

// Boolean por simplicidade sera transformado em int
TypeExpression TYPE_EXPRESSION_VOID = {0, NULL, GTYPE_VOID};
TypeExpression TYPE_EXPRESSION_BOOLEAN = {0, NULL, GTYPE_INT};
TypeExpression TYPE_EXPRESSION_FLOAT = {0, NULL, GTYPE_FLOAT};
TypeExpression TYPE_EXPRESSION_INT = {0, NULL, GTYPE_INT};

GrammarType token_to_type(int token) {
  switch(token) {
    // Boolean por simplicidade sera int
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
        case GTYPE_INT:     sprintf(buffer, "%s", "<int>"); break;  
        case GTYPE_FLOAT:   sprintf(buffer, "%s", "<float>"); break;  
        case GTYPE_GRAPH:   sprintf(buffer, "%s", "graph"); break;  
        case GTYPE_VOID:    sprintf(buffer, "%s", "<void>"); break;  
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
    printf("\033[0;32m");
    printf("%s", buffer);
    printf("\033[0m"); 
    free(buffer);
}

void type_print_cast(Cast cast) {
    // printf("\033[01;33m%d:%d-%d:%d\033[0;0m
    printf("\033[0;31m");
    switch(cast) {
        case CNONE:         printf("NONE"); break;  
        case CINT_TO_FLOAT: printf("INT -> FLOAT"); break;  
        case CFLOAT_TO_INT: printf("FLOAT -> INT"); break;  
        default:            printf("ERROR CAST NON EXISTENT");
    }
    printf("\033[0m"); 
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
    // Grafos tambem funcionam como um array contendo valores armazenados em vertices como inteiro
    if (tbase == GTYPE_GRAPH) {
        texpr->child = type_base(GTYPE_INT);
    }
    return texpr;
}

TypeExpression* type_build(Node *type, Node *dimension) {
    TypeExpression *build = type_base(token_to_type(type->t_token));
    // Pegar todas as dimensoes
    if (dimension) {
        Node *cur = dimension->begin_child;
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
 * @return tipo sendo acessado ou null se acesso é impossivel.
 */
TypeExpression* type_from_access_lvl(TypeExpression* tgt, Node *access_lvl) {
    if (tgt == NULL) {
        return NULL;
    }

    if (access_lvl == NULL) {
        return type_cpy(tgt);
    }

    Node *cur_access = access_lvl->begin_child;
    TypeExpression *cur_type = tgt;
    int matches = 0;

    while(cur_access != NULL) {
        // Caso acesso seja mais profundo do que as dimensoes do tipo
        if (cur_type == NULL) {
            matches = 0;
            break;
        }
        
        // Ainda caso acesso seja mais profundo do que o tipo
        if (cur_type->node_type == GTYPE_ARRAY || cur_type->node_type == GTYPE_GRAPH) {
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

int type_eq(TypeExpression* a, TypeExpression* b) {
    if (a == NULL || b == NULL) {
        return a == b;
    }

    int eq = a->node_type == b->node_type;
    eq &= a->size == b->size;
    return eq && type_eq(a->child, b->child);
}


/**
 * Retorna tipo maximo entre dois termos, caso nao sejam compativeis retorna null
 */
TypeExpression* type_max(TypeExpression* a, TypeExpression* b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }
    
    switch(a->node_type) {
        case GTYPE_INT: {
            switch(b->node_type) {
                case GTYPE_INT:     return a; 
                case GTYPE_FLOAT:   return b;
                default:            break;
            }
            break;
        }  
        case GTYPE_FLOAT: {
            switch(b->node_type) {
                case GTYPE_INT:     return a; 
                case GTYPE_FLOAT:   return a;  
                default:            break;
            }
            break;
        }  
        case GTYPE_GRAPH: {
            switch(b->node_type) {
                case GTYPE_GRAPH:   return b; 
                default:            break;
            }
            break;
        }  
        case GTYPE_ARRAY:   return type_eq(a, b) ? a : NULL;
        case GTYPE_VOID:    break;  
        default: return NULL;
    }
    return NULL;
}

Cast type_get_cast(TypeExpression* tgt, TypeExpression* src) {
    switch(src->node_type) {
        case GTYPE_INT: {
            switch(tgt->node_type) {
                case GTYPE_FLOAT:   return CINT_TO_FLOAT;
                default:            break;
            }
            break;
        }  
        case GTYPE_FLOAT: {
            switch(tgt->node_type) {
                case GTYPE_INT:     return CFLOAT_TO_INT;  
                default:            break;
            }
            break;
        }
        default: return CNONE;
    }
    return 0;
}

/**
 * Verifica se tipo pode receber uma atribuição. 
 */
int type_can_assign(TypeExpression *tgt) {
    if (tgt == NULL) {
        return 0;
    }
    return tgt->node_type == GTYPE_FLOAT || tgt->node_type == GTYPE_INT;
}

int type_is_aritmetic(TypeExpression *type) {
    return type_max(type, &TYPE_EXPRESSION_FLOAT) || type_max(type, &TYPE_EXPRESSION_INT);
}

int type_is_boolean(TypeExpression *type) {
    return type_max(type, &TYPE_EXPRESSION_INT) != NULL;
}

/**
 * Tipos que podem ser retornados em funcoes
 */
int type_can_return(TypeExpression *tgt) {
    if (tgt == NULL) {
        return 0;
    }
    return tgt->node_type == GTYPE_FLOAT || tgt->node_type == GTYPE_INT || tgt->node_type == GTYPE_VOID;
}

void free_type(TypeExpression* type) {
    if (type == NULL) {
        return;
    }
    free_type(type->child);
    free(type);
}