#include "./stack.h"
#include "stdio.h"

void st_n_push (n_stack *s, node* value) {
  s->data[s->top++] = value;
}

bool st_n_is_empty (n_stack *s) {
  return s->top == 0;
}

node* st_n_pop (n_stack *s) {
  if (st_n_is_empty(s)){
    printf("underflow\n");
  } else {
    return s->data[--s->top];
  }
}

node* st_n_top (n_stack *s) {
  if (st_n_is_empty(s)){
    printf("underflow\n");
  } else {
    return s->data[s->top - 1];
  }
}