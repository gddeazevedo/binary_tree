#include "helpers.h"

Stack* newStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, Tree* data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

void push_with_time(Stack* stack, Tree* data, int time) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->time = time;
    node->next = stack->top;
    stack->top = node;
}

Tree* pop(Stack* stack) {
    if (stack->top == NULL) return NULL;
    Node* node = stack->top;
    stack->top = stack->top->next;
    node->next = NULL;
    Tree* data = node->data;
    free(node);
    return data;
}

Node* pop_with_time(Stack* stack) {
    Node* node = stack->top;
    stack->top = stack->top->next;
    node->next = NULL;
    return node;
}

void empty_stack(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
}

Queue* newQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue* q, Tree* data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (q->tail != NULL) {
        q->tail->next = node;
    } else {
        q->head = node;
    }

    q->tail = node;
}

Tree* dequeue(Queue* q) {
    if (q->head != NULL) {
        if (q->head == q->tail) {
            q->tail = NULL;
        }

        Node* node = q->head;
        q->head = q->head->next;

        node->next = NULL;
        Tree* data = node->data;
        free(node);
        node = NULL;
        return data;
    }

    return NULL;
}

void empty_queue(Queue* q) {
    while (q->head != NULL) {
        dequeue(q);
    }
}
