#ifndef __SYNTAX_TREE__
#define __SYNTAX_TREE__
#include "../queue/queue.h"

typedef struct node node;

// helpers
int down(char );
int prior(char );
int operation(char, int, int);
int is_op(char);

//syntax-tree

struct node {
  char tkn;
  node *l;
  node *r;
};

node * build_syntax_tree(queue *);
double eval(node *);

#endif