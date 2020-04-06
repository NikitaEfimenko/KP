#ifndef _QUEUE_
#define _QUEUE_
typedef struct queue queue;
typedef struct elem elem;

struct elem {
    char payload;
    elem * prev;
};

struct queue {
    elem * head;
    elem * tail;
};

char dequeue(queue *);
void enqueue(queue *, char);
void remove_queue(queue *);
void display_from(elem *);
int enqueue_is_empty (queue *); 
#endif
