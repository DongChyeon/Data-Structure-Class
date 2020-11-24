#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

BinaryNode makeNode(char elem, int frequency, BinaryNode left, BinaryNode right) {
    BinaryNode node = (BinaryNode)malloc(sizeof(struct binaryNode));
    node->value = elem;
    node->frequency = frequency;
    node->left = left;
    node->right = right;

    return node;
}

BinaryTree makeTree() {
    BinaryTree tree = (BinaryTree)malloc(sizeof(struct binaryTree));

    return tree;
}

bool isLeaf(BinaryNode node) {
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

bool isTreeEmpty(BinaryTree tree) {
    if (tree->root == NULL) {
        return true;
    } else {
        return false;
    }
}

void setRoot(BinaryTree tree, BinaryNode root) {
    tree->root = root;
}

void inorder(BinaryNode node) {
    if (node != NULL) {
        inorder(node->left);
        printf("[%c] ", node->value);
        inorder(node->right);
    }
}

void preorder(BinaryNode node) {
    if (node != NULL) {
        printf("[%c] ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(BinaryNode node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("[%c] ", node->value);
    }
}

void printInorder(BinaryTree tree) {
    if (isTreeEmpty(tree)) {
        printf("Tree is empty\n");
    }

    printf("inorder\n");
    inorder(tree->root);
    printf("\n");
}

void printPreorder(BinaryTree tree) {
    if (isTreeEmpty(tree)) {
        printf("Tree is empty\n");
    }

    printf("preorder\n");
    postorder(tree->root);
    printf("\n");
}

void printPostorder(BinaryTree tree) {
    if (isTreeEmpty(tree)) {
        printf("Tree is empty\n");
    }

    printf("postorder\n");
    postorder(tree->root);
    printf("\n");
}