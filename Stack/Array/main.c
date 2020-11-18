#include <stdio.h>
#include <string.h>
#include "stack.h"

void parentheses_matching(Stack stack, char *str);
//void infix_to_postfix(char *infix_exp, Stack *stack);
void infix_to_postfix(Stack stack, char *infix_exp);
void infix_to_postfix2(Stack stack, char *infix_exp);
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

void parentheses_matching(Stack stack, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') push(stack, (char) str[i]);
        if (str[i] == ')') pop(stack);
    }
    if (isEmpty(stack))
        printf("The infix_exp holds.\n");
    else
        printf("The infix_exp doesn't hold.\n"); 
}

void infix_to_postfix(Stack stack, char *infix_exp) {
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

/*
void infix_to_postfix(char *infix_exp) {
    char temp;

    for (int i = 0; i < strlen(infix_exp); i++) {
        if (infix_exp[i] == '(') {
            continue;
        } else if (infix_exp[i] == ')') {
            printf("%c", temp);
        } else if (infix_exp[i] >= 65 && infix_exp[i] <= 90) {
            printf("%c", infix_exp[i]);
        } else {
            temp = infix_exp[i];
        }
    }
}
*/

/*
void infix_to_postfix(Stack stack, char *infix_exp) {
    for (int i = 0; i < strlen(infix_exp); i++) {
        if (infix_exp[i] == '(') {
            continue;
        } else if (infix_exp[i] == ')') {
            printf("%c", pop(stack));
        } else if (infix_exp[i] >= 65 && infix_exp[i] <= 90) {
			printf("%c", infix_exp[i]);
        } else {
            push(stack, infix_exp[i]);
        }
    }
}
*/

void infix_to_postfix2(Stack stack, char *infix_exp) {
    char temp;

    for (int i = 0; i < strlen(infix_exp); i++) {
        if (infix_exp[i] == '(') {
            push(stack, infix_exp[i]);
        } else if (infix_exp[i] == ')') {
            while (1) {
                temp = pop(stack);
                if (temp == '(') {
                    break;
                }
                printf("%c", temp);
            }
        } else if (infix_exp[i] >= 65 && infix_exp[i] <= 90) {
			printf("%c", infix_exp[i]);
        } else {
            if (priority(stack->element[stack->top]) >= priority(infix_exp[i])) {
                printf("%c", pop(stack));
            }
            push(stack, infix_exp[i]);
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