#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
#include "stack.h"

BinaryTree infix_to_postfix(char *equation);
int priority(char oper); 

BinaryTree infix_to_postfix(char *equation) {
    BinaryTree tree = makeTree();
    BinaryNode node;
    BinaryNode center, left, right;

    Stack operator = makeStack();
    Stack operand = makeStack();

    for (int i = 0; i < strlen(equation); i++) {
        if (equation[i] == '(') {
            node = makeNode('(', NULL, NULL);
            push(operator, node);
        } else if (equation[i] == ')') {
            while (1) {
                center = pop(operator);
                if (center->value == '(') {
                    break;
                }
                right = pop(operand);
                left = pop(operand);
                center->left = left;
                center->right = right;
                push(operand, center);
            }
        } else if (equation[i] >= 65 && equation[i] <= 90) {
            node = makeNode(equation[i], NULL, NULL);
            push(operand, node);
        } else {
            if (operator->top != NULL && priority(operator->top->element->value) >= priority(equation[i])) {
                center = pop(operator);
                right = pop(operand);
                left = pop(operand);
                center->left = left;
                center->right = right;
                push(operand, center);
            }
            node = makeNode(equation[i], NULL, NULL);
            push(operator, node);
        }
    }
    
    while (operator->top != NULL) {
        center = pop(operator);
        right = pop(operand);
        left = pop(operand);
        center->left = left;
        center->right = right;
        push(operand, center);
    }

    setRoot(tree, pop(operand));

    deleteStack(operator);
    deleteStack(operand);

    return tree;
}

int priority(char oper) {
    if (oper == '*' || oper == '/') return 2;
    else if (oper == '+' || oper == '-') return 1;
    else return 0;
}

int main() {
    char *equation = "A+B*(C-D)/E";

    BinaryTree tree = infix_to_postfix(equation);

    printInorder(tree);
    printPreorder(tree);
    printPostorder(tree);
    printLevelorder(tree);

    return 0; 
}