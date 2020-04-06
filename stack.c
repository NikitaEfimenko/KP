#include "stdio.h"
#include "stdlib.h"

#define SIZE 100

typedef enum _bool { false, true } bool;

typedef struct _Entry {
  int value;
} Entry;

typedef struct _Stack {
  Entry data [SIZE];
  size_t top;
} Stack; 

void printStack(Stack *s){
  for (int i = 0; i < s->top; ++i) {
    printf("%d ", s->data[i].value);
  }
  printf("\n");
}

void push (Stack *s, Entry value){
  s->data[s->top++] = value;
}

bool isEmpty (Stack *s){
  return s->top == 0;
}

Entry pop (Stack *s){
  if (isEmpty(s)){
    printf("underflow\n");
  } else {
    return s->data[--s->top];
  }
}


void test(int size){
  Stack s = {.top = 0};
  Stack reverse = {.top = 0};
  for (int i = 0; i < size; ++i) {
    Entry v = { i };
    push(&s, v);
  }
  printStack(&s);
  for (int i = 0; i < size; ++i){
    push(&reverse, pop(&s));
  }
  printStack(&reverse);
}

