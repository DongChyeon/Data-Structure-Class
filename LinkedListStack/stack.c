#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool isEmpty(Stack stack) {
    if (stack->top == NULL)
        return true;
    else
        return false;
}

void printStackItems(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    list_pointer tnode = stack->top;
    while (tnode != NULL) {
        printf("%d\t", tnode->value);
        tnode = tnode->link;
    }
    printf("\n");
}

Stack makeStack() {
    Stack stack = (Stack)malloc(sizeof(struct head_pointer));
    stack->top = NULL;

    return stack;
}

void push(Stack stack, Element elem) {
    list_pointer ptrNode = (list_pointer)malloc(sizeof(struct list_node));
    if (ptrNode == NULL) {
        printf("::Unable to allocate more memory!!!\n");
    }
    ptrNode->value = elem;
    if (isEmpty(stack)) {
        stack->top = ptrNode;
        ptrNode->link = NULL;
    } else {
        ptrNode->link = stack->top;
        stack->top = ptrNode;
    }
}

Element pop(Stack stack) {
    Node node = stack->top;
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");

        return -999;
    }
    else {
        Element elem = node->value;
        stack->top = node->link;
        free(node);

        return elem;
    }
}

void makeStackEmpty(Stack stack) {
    Node anode = stack->top;
    Node bnode;
    while (anode != NULL) {
        bnode = anode->link;
        free(anode);
        anode = bnode;
    }
    stack->top = NULL;
}

void deleteStack(Stack stack) {
    makeStackEmpty(stack);
    free(stack);
}