#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *create (int n) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->element = (int *) malloc(sizeof(int) * n);
    stack->max_size = n;
    stack->top = 0;

    return stack;
}

bool isFull(Stack *stack) {
    if (stack->top == stack->max_size) 
        return true;
    else 
        return false; 
}

void push(Stack *stack, int elem) {
    if (!isFull(stack)) {
        stack->element[stack->top++] = elem;
    }
}

bool isEmpty(Stack *stack) {
    if (stack->top == 0) 
        return true;
    else 
        return false;
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->element[stack->top--];
    }
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->top; i++) {
        printf("%d ", stack->element[i]);
    }
    printf("\n");
}