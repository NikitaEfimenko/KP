#include "stdio.h"
#include "stdlib.h"
#include "./syntax.h"
#include "../node_stack/stack.h"
#include "../queue/queue.h"

// helpers
int down(char c){
	return c == ')' || c == '+' || c == '-' || c == '/' || c == '*';
}

int prior(char c){
	switch(c){
		case '(': return 1;
		case ')': return 2;
		case '+': return 3;
		case '-': return 3;
		case '*': return 4;
		case '/': return 4;
	}
}

int operation(char op, int a, int b){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int is_op(char c){
	return c == '+' || c == '-' ||c == '*' ||c == '/';
}

node* build_syntax_tree(queue * polish) {
    n_stack s = {.top = 0};
    char c;
    while(!enqueue_is_empty(polish)) {
        c = dequeue(polish);        
        if (is_op(c)) {
            node * rc = st_n_pop(&s);
            node * lc = st_n_pop(&s);
            node * n = (node *) malloc(sizeof(n));
            n->tkn = c;
            n->l = lc;
            n->r = rc;
            st_n_push(&s, n);
        } else {
            node * n = (node *) malloc(sizeof(n));
            n->tkn = c;
            n->l = NULL;
            n->r = NULL;
            st_n_push(&s, n);
        }
    }
    return st_n_pop(&s);
}

double eval(node * root) {
    char tkn = root->tkn;
    return is_op(tkn) ? 
        operation(tkn, eval(root->l), eval(root->r)) 
        : atoi(&tkn);
}
// syntax-tree
