#include <stdio.h>
#include <string.h>
#include "stack.h"

void parentheses_matching(Stack *stack, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') push(stack, i);
        if (str[i] == ')') pop(stack);
    }
    if (isEmpty(stack))
        printf("The equation holds.\n");
    else
        printf("The equation doesn't hold.\n"); 
}

int main() {
    Stack *stack = create(10);
    char str[] = "((a+b)*c)";

    parentheses_matching(stack, str);

    return 0;
}