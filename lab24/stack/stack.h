#ifndef __STACK__
#define __STACK__
#define SIZE 100

typedef enum _bool { false, true } bool;


typedef struct _Stack {
  char data [SIZE];
  int top;
} stack; 


void st_push (stack *, char);
bool st_is_empty (stack *);
char st_pop (stack *);
char st_top (stack *);
#endif