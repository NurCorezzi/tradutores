#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "ast.h"
#include "type_expression.h"

void (*tree_prefix[150]) (void);
int i_prefix = 0;
Node *allocated;

Node* create_node(char const *id) {
  Node* node = (Node*)calloc(1, sizeof(Node));
  
  char* cpy = (char*)malloc(strlen(id) + 1);
  strcpy(cpy, id);
  node->id = cpy;
  
  return node;
}

Node* create_node_with_type(char const *id, TypeExpression *type) {
  Node* node = create_node(id);
  node->type = type_cpy(type);
  return node;
}

Node* last_node(Node *node) {
  if (node == NULL) {
    return NULL;
  }

  Node *it = node;
  while(it->next != NULL) {
    it = it->next;
  }
  return it;
}

void push_child(Node *root, Node *child) {
  if (child == NULL) {
    return;
  }
  if (root->begin_child == NULL) {
    root->begin_child = child;
    root->end_child = child;
  } else {
    root->end_child->next = child;
    root->end_child = child;
  }
  child->next = NULL;
}

void free_node(Node *node) {
  if (node->id != NULL) free(node->id);
  if (node->complement != NULL) free(node->complement);
  if (node->type != NULL) free_type(node->type);
  free(node);
}

void free_tree(Node *root) {
  if (root == NULL) return;

  Node *it = root->begin_child;
  while (it != NULL) {
    Node *next = it->next;
    free_tree(it);
    it = next;
  }
  free_node(root);
}

/*------------PRINT TREE---------------*/

void print_l_end() {printf("└");}
void print_l_middle() {printf("├");}
void print_horizontal() {printf("─");}
void print_vertical() {printf("│");}
void print_space() {printf(" ");}

void print_node_prefix() {
  int i;
  for (i = 0; i < i_prefix; ++i) {
    (*tree_prefix[i])();
  }
}

void print_node_sufix(Node *node) {
  printf("%s", node->id);
  if (node->complement) printf(": %s", node->complement);
  if (node->type) {
    printf(" - ");
    type_print(node->type);
    if (node->cast) {
      printf(":(");
      type_print_cast(node->cast);
      printf(")");
    }
  }
  printf("\n");
}

void print_node(Node *node, int isLast) {
  tree_prefix[i_prefix-1] = &print_space;
  if (isLast) {
    tree_prefix[i_prefix-3] = &print_l_end;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_node_prefix();
    print_node_sufix(node);
    tree_prefix[i_prefix-3] = &print_space;
    tree_prefix[i_prefix-2] = &print_space;
  } else {
    tree_prefix[i_prefix-3] = &print_l_middle;
    tree_prefix[i_prefix-2] = &print_horizontal;
    print_node_prefix();
    print_node_sufix(node);
    tree_prefix[i_prefix-3] = &print_vertical;
    tree_prefix[i_prefix-2] = &print_space;
  }  
}

void print_tree(Node *node, int isLast) {
  if (node == NULL) return;

  i_prefix += 3;
  print_node(node, isLast);  
  Node *it;

  for (it = node->begin_child; it != NULL; it = it->next) {
    print_tree(it, it == node->end_child);
  }
  i_prefix -= 3;
}