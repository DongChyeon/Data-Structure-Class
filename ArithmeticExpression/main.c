#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
#include "stack.h"

BinaryTree infix_to_postfix(char *infix_exp);
int priority(char oper); 

BinaryTree infix_to_postfix(char *infix_exp) {
    BinaryTree tree = makeTree();
    BinaryNode node;
    BinaryNode center, left, right;

    Stack operator = makeStack();
    Stack operand = makeStack();

    for (int i = 0; i < strlen(infix_exp); i++) {
        if (infix_exp[i] == '(') {
            node = makeNode('(', NULL, NULL);
            push(operator, node);
        } else if (infix_exp[i] == ')') {
            // make tree and push to stack
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
            // push operand to stack
        } else if (infix_exp[i] >= 65 && infix_exp[i] <= 90) {
            node = makeNode(infix_exp[i], NULL, NULL);
            push(operand, node);
        } else {
            if (operator->top != NULL && priority(operator->top->element->value) >= priority(infix_exp[i])) {
                center = pop(operator);
                right = pop(operand);
                left = pop(operand);
                center->left = left;
                center->right = right;
                push(operand, center);
            }
            node = makeNode(infix_exp[i], NULL, NULL);
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
    char infix_exp[128];
    printf("Please enter a infix expression : ");
    scanf_s("%s", &infix_exp, sizeof(infix_exp));

    BinaryTree tree = infix_to_postfix(infix_exp);

    printf("inorder\n");
    inorder(tree->root);
    printf("\npreorder\n");
    preorder(tree->root);
    printf("\npostorder\n");
    postorder(tree->root);
    printf("\nlevelorder\n");
    levelorder(tree->root);

    return 0; 
}