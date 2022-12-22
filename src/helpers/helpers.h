#ifndef __helpers_h
#define __helpers_h

#include "../types.h"
#include <stdlib.h>

Stack* newStack();
void push(Stack* stack, Tree* data);
void push_with_time(Stack* stack, Tree* data, int time);
Tree* pop(Stack* stack);
Node* pop_with_time(Stack* stack);
void empty_stack(Stack* stack);

Queue* newQueue();
void enqueue(Queue* q, Tree* data);
Tree* dequeue(Queue* q);
void empty_queue(Queue* q);

#endif
