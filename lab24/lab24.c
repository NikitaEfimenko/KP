#include <stdio.h>
#include <stdlib.h>
#include "./stack/stack.h"
#include "./queue/queue.h"
#include "./syntax/syntax.h"

int* ratishauser_map(char * expr) {
  int len = 0;
  int k = 0;
  while (expr[++len] != '\0');
  int* map = (int *) calloc(sizeof(int), len);
  for (int i = 0; i < len; ++i) {
    map[i] = down(expr[i]) ? --k: ++k;
  }
  return map;
}

queue * dijkstra_parse(char * expr) {
  stack s = {.top = 0};
  queue* q = (queue *)malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  int i = 0;
  char c, c1;
  while(expr[i] != '\0') {
    c = expr[i++];
    if (is_op(c)) {
      while (!st_is_empty(&s)) {
        c1 = st_top(&s);
        if (prior(c) <= prior(c1)) {
          enqueue(q, c1);
          st_pop(&s);
        } else break;
      }
      st_push(&s, c);
    } else if (c == '(') {
      st_push(&s, c);
    } else if (c == ')') {
      while (!st_is_empty(&s)) {
        c1 = st_pop(&s);
        if (c1 == '(') {
          break;
        } else {
          enqueue(q, c1);
        }
      }
    } else {
      enqueue(q, c);
    }
  }
  while (!st_is_empty(&s)) {
    enqueue(q, st_pop(&s));
  }
  return q;
}

void print_arr(int * arr) {
  int len = 0;
  while (arr[++len] != '\0');
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char ** argv) {
  char expr[100];
  queue * polish = NULL;
  for(;;) {
    scanf("%s", expr);
    //print_arr(ratishauser_map(expr));
    
    polish = dijkstra_parse(expr);
    printf("polish:");
    display_from(polish->head);
    printf("\n");
    node * root = build_syntax_tree(polish);
    printf("$:%lf", eval(root));
  }

