#include <stdio.h>
#include <string.h>
#include "stack.h"

void parentheses_matching(Stack *stack, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') push(stack, (char) str[i]);
        if (str[i] == ')') pop(stack);
    }
    if (isEmpty(stack))
        printf("The equation holds.\n");
    else
        printf("The equation doesn't hold.\n"); 
}


void infix_to_postfix(Stack *stack, char *equation) {
    for (int i = 0; i < strlen(equation); i++) {
        if (equation[i] == '(') {
            continue;
        } else if (equation[i] == ')') {
            printf("%c", pop(stack));
        } else if (equation[i] >= 65 && equation[i] <= 90) {
			printf("%c", equation[i]);
        } else {
            push(stack, equation[i]);
        }
    }
}


int main() {
    Stack *stack = create(10);
    char *str = "((A+B)*C)";

    //parentheses_matching(stack, str);
    infix_to_postfix(stack, str);

    return 0;
}