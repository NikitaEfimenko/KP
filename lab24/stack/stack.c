#include "./stack.h"
#include "stdio.h"

void st_push (stack *s, char value) {
  s->data[s->top++] = value;
}

bool st_is_empty (stack *s) {
  return s->top == 0;
}

char st_pop (stack *s) {
  if (st_is_empty(s)){
    printf("underflow\n");
  } else {
    return s->data[--s->top];
  }
}

char st_top (stack *s) {
  if (st_is_empty(s)){
    printf("underflow\n");
  } else {
    return s->data[s->top - 1];
  }
}