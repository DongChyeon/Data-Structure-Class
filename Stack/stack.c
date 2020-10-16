#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *create(int n) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->element = (char *) malloc(sizeof(char) * n);
    stack->size = n;
    stack->top = 0;

    return stack;
}

bool isFull(Stack *stack) {
    if (stack->top == stack->size + 1) 
        return true;
    else 
        return false; 
}

void push(Stack *stack, char elem) {
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

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
        return stack->element[stack->top];
    }
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->top; i++) {
        printf("%c ", stack->element[i]);
    }
    printf("\n");
}