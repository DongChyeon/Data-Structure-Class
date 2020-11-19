#include <stdio.h>
#include <string.h>
#include "stack.h"

void infix_to_postfix( char *infix_exp);
double postfix_calculate(char *postfix_infix_exp);
int priority(char oper);

void infix_to_postfix(char *infix_exp) {
    Stack operator = makeStack();
    char temp;

    for (int i = 0; i < strlen(infix_exp); i++) {
        if (infix_exp[i] == '(') {
            push(operator, infix_exp[i]);
        } else if (infix_exp[i] == ')') {
            while (1) {
                temp = pop(operator);
                if (temp == '(') {
                    break;
                }
                printf("%c", temp);
            }
        } else if (infix_exp[i] == '*' || infix_exp[i] == '/' || infix_exp[i] == '+' || infix_exp[i] == '-') {
            if (operator->top != NULL && priority(operator->top->element) >= priority(infix_exp[i])) {
                printf("%c", pop(operator));
            }
            push(operator, infix_exp[i]);
        } else {
			printf("%c", infix_exp[i]);
        }
    }
    
    while (operator->top != NULL) {
        printf("%c", pop(operator));
    }
}


double postfix_calculate(char *postfix_infix_exp) {
    double one, two;
    Stack operand = makeStack();

    for (int i = 0; i < strlen(postfix_infix_exp); i++) {
        switch (postfix_infix_exp[i]) {
            case '*':
                one = pop(operand);
                two = pop(operand);
                push(operand, two * one);
                break;
            case '/':
                one = pop(operand);
                two = pop(operand);
                push(operand, two / one);
                break;
            case '+':
                one = pop(operand);
                two = pop(operand);
                push(operand, two + one);
                break;
            case '-':
                one = pop(operand);
                two = pop(operand);
                push(operand, two - one);
                break;
            default:
                push(operand, (int)postfix_infix_exp[i] - 48);
                break;
        }
    }

    return pop(operand);
}

int priority(char oper) {
    if (oper == '*' || oper == '/') return 2;
    else if (oper == '+' || oper == '-') return 1;
    else return 0;
}

int main() {
    char *str = "1+2/(3+4)";

    char *postfix_exp = infix_to_postfix(str);
    /*
    printf("%lf\n", postfix_calculate(str1));
    printf("%lf", postfix_calculate(str2));
    */
    return 0;
}