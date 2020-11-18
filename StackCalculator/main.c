#include <stdio.h>
#include <string.h>
#include "stack.h"

void infix_to_postfix(Stack *stack, char *infix_exp);
double postfix_calculate(char *postfix_infix_exp, Stack *stack);

void infix_to_postfix(Stack *stack, char *infix_exp) {
    char temp;

    for (int i = 0; i < strlen(infix_exp); i++) {
        if (infix_exp[i] == '(') {
            continue;
        } else if (infix_exp[i] == ')') {
            push(stack, temp);
        } else if (infix_exp[i] == '*' || infix_exp[i] == '/' || infix_exp[i] == '+' || infix_exp[i] == '-') {
            temp = infix_exp[i];
        } else {
            push(stack, infix_exp[i]);
        }
    }
}

double postfix_calculate(char *postfix_infix_exp, Stack *stack) {
    double one, two;

    for (int i = 0; i < strlen(postfix_infix_exp); i++) {
        switch (postfix_infix_exp[i]) {
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
                push(stack, (int)postfix_infix_exp[i] - 48);
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