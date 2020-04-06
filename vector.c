#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct vector vector;

typedef enum { INTEGER, DOUBLE, STRING } TYPE;

typedef union { int d; double lf; char s[32]; } UNION_ENTITY;

#define SET_VALUE(type, un, v)  if (type == INTEGER) { un.d = v.d;} \
                                if (type == DOUBLE) { un.lf = v.lf;} \
                                if (type == STRING) { strcpy(un.s, v.s);} 



struct vector {
    TYPE type;
    int capacity;
    int size;
    UNION_ENTITY * data;
};

vector * create_vector(TYPE type, int size) {
    vector * v = (vector *) malloc(sizeof(vector));
    v->capacity = size;
    v->size = size;
    v->type = type;
    v->data = (UNION_ENTITY *) malloc(sizeof(UNION_ENTITY) * size);
    if (type == INTEGER) for(int i = 0; i < size; ++i) { v->data[i].d = 0;}
    if (type == DOUBLE)  for(int i = 0; i < size; ++i) { v->data[i].lf = .0; };
    if (type == STRING)  for(int i = 0; i < size; ++i) { strcpy(v->data[i].s, ""); };
    return v;
}

void vector_set(vector *v, int i, UNION_ENTITY val) {
    if (v->size > i) {
        SET_VALUE(v->type, v->data[i], val)
    }
}
UNION_ENTITY vector_get(vector * v, int i) {
    if (v->size > i) {
        return v->data[i];
    }
}

void print_vector(vector * v) {
    for (int i = 0; i < v->size - 1; ++i) {
        UNION_ENTITY tmp = vector_get(v, i);
        if (v->type == INTEGER) printf("%d", tmp.d);
        if (v->type == DOUBLE) printf("%lf", tmp.lf);
        if (v->type == STRING) printf("%s", tmp.s);
        printf(",");
    }
    UNION_ENTITY tmp = vector_get(v, v->size - 1);
    if (v->type == INTEGER) printf("%d", tmp.d);
    if (v->type == DOUBLE) printf("%lf", tmp.lf);
    if (v->type == STRING) printf("%s", tmp.s);
    printf("\n");
}

void delete_vector(vector * v) {
    UNION_ENTITY * tmp = v->data;
    free(v);
    free(tmp);
}

int main(int argc, char ** argv) {
    vector* v = create_vector(INTEGER, atoi(argv[1]));
    UNION_ENTITY val = { .d = 7};
    vector_set(v, 3, val);
    vector_set(v, 0, val);
    print_vector(v);
    delete_vector(v);
}