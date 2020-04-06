#ifndef __NODE_STACK__
#define __NODE_STACK__
#define SIZE 100
#include "../syntax/syntax.h"
typedef enum _bool { false, true } bool;


typedef struct _n_Stack {
  node* data [SIZE];
  int top;
} n_stack; 


void st_n_push (n_stack *, node*);
bool st_n_is_empty (n_stack *);
node* st_n_pop (n_stack *);
node* st_n_top (n_stack *);
#endif