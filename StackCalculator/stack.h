#include <stdbool.h>

#ifndef _STACK_
#define _STACK_

typedef struct {
        double *element;
        int size;
        int top;
} Stack;

Stack *create(int n);
bool isFull(Stack *stack);
void push(Stack *stack, double elem);
bool isEmpty(Stack *stack);
double pop(Stack *stack);
void printStack(Stack *stack);

#endif