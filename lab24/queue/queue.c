#include "./queue.h"
#include "stdio.h"
#include "stdlib.h"

char dequeue(queue * q) {
    if (q -> tail != NULL) {
        elem * tmp = q -> head;
        char value = tmp->payload;
        q -> head = q -> head -> prev;
        free(tmp);
        return value;
    }
}

int enqueue_is_empty (queue *q) {
    return q->head == NULL;
}

void enqueue(queue * q, char v) {
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

void display_from(elem * e) {
    if (e == NULL) {
    } else {
        printf("%c", e -> payload);
        display_from(e -> prev);
    }
}
