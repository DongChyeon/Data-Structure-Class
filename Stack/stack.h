#include <stdbool.h>

typedef struct {
        int *element;
        int max_size;
        int top;
} Stack;

Stack *create (int n);
bool isFull(Stack *stack);
void push(Stack *stack, int elem);
bool isEmpty(Stack *stack);
int pop(Stack *stack);
void printStack(Stack *stack);