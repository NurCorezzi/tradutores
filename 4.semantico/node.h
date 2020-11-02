#ifndef NODE_H
#define NODE_H

typedef struct t_node {
    // Inicio e termino da lista de filhos
    struct t_node *beginChild;
    struct t_node *endChild;
    // Proximo termo da lista que termo compoe
    struct t_node *next;

    struct t_type_expression *type;
    struct t_symbol_node *sentry;
    char *id;
    char *complement;
    int t_token;
} Node;

typedef enum {
    STYPE_FUNCTION, STYPE_VARIABLE
} SymbolType;

typedef enum {
    GTYPE_BOOLEAN, GTYPE_INT, GTYPE_FLOAT, GTYPE_GRAPH, GTYPE_VOID, GTYPE_ARRAY
} GrammarType;

typedef struct t_type_expression {
    int size;
    struct t_type_expression *child;
    GrammarType node_type;
} TypeExpression;

typedef struct t_scope {
    int id;
    struct t_scope *child;
} Scope;
typedef struct t_symbol_node {
    char *id;
    char *scope_str;

    Scope *scope;
    SymbolType stype;
    GrammarType gtype;
    Node *ast_node;

    struct t_symbol_node *matches;
    struct t_symbol_node *next;
} SymbolNode;

void scope_push();
void scope_pop();

SymbolNode *symbol_table;
Node *ast;
Scope *global_scope;
int scope_count;

#endif