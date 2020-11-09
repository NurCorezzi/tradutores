#ifndef NODE_H
#define NODE_H

typedef enum {
    STYPE_FUNCTION, STYPE_VARIABLE
} SymbolType;

typedef enum {
    GTYPE_INT, GTYPE_FLOAT, GTYPE_GRAPH, GTYPE_VOID, GTYPE_ARRAY
} GrammarType;

typedef enum {
    CNONE, CINT_TO_FLOAT, CFLOAT_TO_INT
} Cast;

typedef struct t_node {
    // Inicio e termino da lista de filhos
    struct t_node *begin_child;
    struct t_node *end_child;
    // Proximo termo da lista que termo compoe
    struct t_node *next;

    Cast cast;
    struct t_type_expression *type;
    struct t_symbol_node *sentry;
    char *id;
    char *complement;
    int t_token;
} Node;

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
    char *type_str;

    SymbolType stype;
    TypeExpression *type;
    Scope *scope;
    Node *ast_node;

    struct t_symbol_node *matches;
    struct t_symbol_node *next;
} SymbolNode;

SymbolNode *symbol_table;
Node *ast;
Scope *global_scope;
int scope_count;

char* type_to_string(TypeExpression* type);
TypeExpression* type_cpy(TypeExpression* src);
GrammarType token_to_type(int token);

void scope_push();
void scope_pop();

#endif