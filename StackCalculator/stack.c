#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *create(int n) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->element = (double *) malloc(sizeof(int) * n);
    stack->size = n;
    stack->top = -1;

    return stack;
}

bool isFull(Stack *stack) {
    if (stack->top == stack->size - 1) 
        return true;
    else 
        return false; 
}

void push(Stack *stack, double elem) {
    if (!isFull(stack)) {
        stack->top++;
        stack->element[stack->top] = elem;
    }
}

bool isEmpty(Stack *stack) {
    if (stack->top == -1) 
        return true;
    else 
        return false;
}

double pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->element[stack->top--];
    }
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->top + 1; i++) {
        printf("%lf ", stack->element[i]);
    }
    printf("\n");
}