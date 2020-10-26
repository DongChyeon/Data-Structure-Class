#include <stdio.h>
#include <string.h>
#include "stack.h"

void infix_to_postfix(Stack *stack, char *equation);
double postfix_calculate(char *postfix_equation, Stack *stack);

void infix_to_postfix(Stack *stack, char *equation) {
    char temp;

    for (int i = 0; i < strlen(equation); i++) {
        if (equation[i] == '(') {
            continue;
        } else if (equation[i] == ')') {
            push(stack, temp);
        } else if (equation[i] == '*' || equation[i] == '/' || equation[i] == '+' || equation[i] == '-') {
            temp = equation[i];
        } else {
            push(stack, equation[i]);
        }
    }
}

double postfix_calculate(char *postfix_equation, Stack *stack) {
    double one, two;

    for (int i = 0; i < strlen(postfix_equation); i++) {
        switch (postfix_equation[i]) {
            case '*':
                one = pop(stack);
                two = pop(stack);
                push(stack, two * one);
                break;
            case '/':
                one = pop(stack);
                two = pop(stack);
                push(stack, two / one);
                break;
            case '+':
                one = pop(stack);
                two = pop(stack);
                push(stack, two + one);
                break;
            case '-':
                one = pop(stack);
                two = pop(stack);
                push(stack, two - one);
                break;
            default:
                push(stack, (int)postfix_equation[i] - 48);
                break;
        }
    }

    return pop(stack);
}

int main() {
    Stack *stack1 = create(10);
    Stack *stack2 = create(10);
    char *str1 = "12+3*4-";
    char *str2 = "1234/-*5+6/7+";

    printf("%lf\n", postfix_calculate(str1, stack1));
    printf("%lf", postfix_calculate(str2, stack2));

    return 0;
}