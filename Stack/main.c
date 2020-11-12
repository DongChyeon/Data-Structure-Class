#include <stdio.h>
#include <string.h>
#include "stack.h"

void parentheses_matching(Stack *stack, char *str);
//void infix_to_postfix(char *equation, Stack *stack);
void infix_to_postfix(Stack *stack, char *equation);
void infix_to_postfix2(Stack *stack, char *equation);
int priority(char oper);

int main() {
    Stack *stack = create(10);

    char *str = "A+B*C-D/E+F";
    //char *str = "(((A+B)*C)-D)";

    //parentheses_matching(stack, str);
    //infix_to_postfix(stack, str);
    infix_to_postfix2(stack, str);

    return 0;
}

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

/*
void infix_to_postfix(char *equation) {
    char temp;

    for (int i = 0; i < strlen(equation); i++) {
        if (equation[i] == '(') {
            continue;
        } else if (equation[i] == ')') {
            printf("%c", temp);
        } else if (equation[i] >= 65 && equation[i] <= 90) {
            printf("%c", equation[i]);
        } else {
            temp = equation[i];
        }
    }
}
*/

/*
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
*/

void infix_to_postfix2(Stack *stack, char *equation) {
    char temp;

    for (int i = 0; i < strlen(equation); i++) {
        if (equation[i] == '(') {
            push(stack, equation[i]);
        } else if (equation[i] == ')') {
            while (1) {
                temp = pop(stack);
                if (temp == '(') {
                    break;
                }
                printf("%c", temp);
            }
        } else if (equation[i] >= 65 && equation[i] <= 90) {
			printf("%c", equation[i]);
        } else {
            if (priority(stack->element[stack->top]) >= priority(equation[i])) {
                printf("%c", pop(stack));
            }
            push(stack, equation[i]);
        }
    }
    
    while (stack->top != -1) {
        printf("%c", pop(stack));
    }
}

int priority(char oper) {
    if (oper == '*' || oper == '/') return 2;
    else if (oper == '+' || oper == '-') return 1;
    else return 0;
}