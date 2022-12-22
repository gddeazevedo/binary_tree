#ifndef __types_h
#define __types_h

typedef struct __tree {
    char data;
    int c;
    struct __tree* left;
    struct __tree* right;
} Tree;

typedef struct __node {
    Tree* data;
    int time;
    struct __node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

#endif
