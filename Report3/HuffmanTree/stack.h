#include <stdbool.h>
#include "binaryTree.h"

#ifndef _STACK_
#define STACK

typedef struct list_node* list_pointer;
typedef struct head_pointer* LinkedList;
typedef LinkedList Stack;
typedef list_pointer Node;
typedef struct list_node {
    BinaryNode element;
    list_pointer link;
} list_node;
typedef struct head_pointer {
    list_pointer top;
} head_pointer;

bool isEmpty(Stack stack);
void printStackItems(Stack stack);
Stack makeStack();
void push(Stack stack, BinaryNode elem);
BinaryNode pop(Stack stack);
void makeStackEmpty(Stack stack);
void deleteStack(Stack stack);

#endif