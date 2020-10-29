#ifndef NODE_H
#define NODE_H

typedef struct t_node {
    // Inicio e termino da lista de filhos
    struct t_node *beginChild;
    struct t_node *endChild;
    // Proximo termo da lista que termo compoe
    struct t_node *next;

    struct t_symbol_node *sentry;
    char *id;
    char *complement;
    int t_token;
} Node;

typedef enum {
    STYPE_FUNCTION, STYPE_VARIABLE
} SymbolType;

typedef enum {
    GTYPE_BOOLEAN, GTYPE_INT, GTYPE_FLOAT, GTYPE_GRAPH, GTYPE_VOID
} GrammarType;

typedef struct t_symbol_node {
    char *id;
    char *scope;

    SymbolType stype;
    GrammarType gtype;
    Node *ast_node;

    struct t_symbol_node *matches;
    struct t_symbol_node *next;
} SymbolNode;

#endif