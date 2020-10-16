#include <stdbool.h>

typedef struct {
        char *element;
        int size;
        int top;
} Stack;

Stack *create(int n);
bool isFull(Stack *stack);
void push(Stack *stack, char elem);
bool isEmpty(Stack *stack);
char pop(Stack *stack);
void printStack(Stack *stack);