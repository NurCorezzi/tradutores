#ifndef NODE_H
#define NODE_H

typedef struct t_node {
struct t_node *father;
// Inicio e termino da lista de filhos
struct t_node *beginChild;
struct t_node *endChild;
// Proximo termo da lista que termo compoe
struct t_node *next;

char *id;
} Node;

#endif