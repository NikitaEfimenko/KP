#include "stdio.h"
#include "stdlib.h"

typedef struct queue queue;
typedef struct elem elem;

struct elem {
    int payload;
    elem * prev;
};


struct queue {
    elem * head;
    elem * tail;
};

void dequeue(queue * q) {
    if (q -> tail != NULL) {
        elem * tmp = q -> head;
        q -> head = q -> head -> prev;
        free(tmp);
    }
}

void enqueue(queue * q, int v) {
    elem * e = (elem *)malloc(sizeof(elem));
    e->payload = v;
    e->prev = NULL;
    if (q -> head == NULL) {
        q -> head = e;
        q -> tail = e;
    } else {
        q -> tail -> prev = e;
        q -> tail = e;
    }
}

void remove_queue(queue *q) {
    elem * iter = q->head;
    elem * to_del = NULL;
    while (iter != NULL) {
        to_del = iter;
        iter = iter -> prev;
        free(to_del);
    }
    q->head = NULL;
    q->tail = NULL;
}

void displayFrom(elem * e) {
    if (e == NULL) {
        printf("NULL<-");
    } else {
        printf("%d<-", e -> payload);
        displayFrom(e -> prev);
    }
}

int main() {

    queue q;
    q.head = NULL;
    q.tail = NULL;
    
    enqueue(&q, 2);
    enqueue(&q, 6);
    enqueue(&q, 44);
    enqueue(&q, 2);
    enqueue(&q, 8);
    enqueue(&q, 0);
    displayFrom(q.head);
    printf("\n");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    displayFrom(q.head);
    remove_queue(&q);
    printf("\n");
}
