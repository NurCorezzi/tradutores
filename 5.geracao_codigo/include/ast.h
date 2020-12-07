#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "code_gen.h"
#include "node.h"

Node* create_node(char const *id);
Node* create_node_with_type(char const *id, TypeExpression *type);

void push_child(Node *root, Node *child);

void free_node(Node *node);
void free_tree(Node *root);

/*------------PRINT TREE---------------*/

void print_l_end();
void print_l_middle();
void print_horizontal();
void print_vertical();
void print_space();
void print_node_prefix();

void print_node_sufix(Node *node);

void print_node(Node *node, int isLast);
void print_tree(Node *node, int isLast);
#endif