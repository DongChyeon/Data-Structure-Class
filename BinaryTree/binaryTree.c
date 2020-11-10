#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

BinaryNode makeNode(int elem, BinaryNode left, BinaryNode right) {
    BinaryNode node = (BinaryNode)malloc(sizeof(struct binaryNode));
    node->value = elem;
    node->left = left;
    node->right = right;

    return node;
}

void setData(BinaryNode node, int elem) {
    node->value = elem;
}

void setLeft(BinaryNode node, BinaryNode left) {
    node->left = left;
}

void setRight(BinaryNode node, BinaryNode right) {
    node->right = right;
}

Element getData(BinaryNode node) {
    return node->value;
}

BinaryTree makeTree(BinaryNode root) {
    BinaryTree tree = (BinaryTree)malloc(sizeof(struct binaryTree));

    return tree;
}

void setRoot(BinaryTree tree, BinaryNode root) {
    tree->root = root;
}

BinaryNode getRoot(BinaryTree tree) {
    return tree->root;
}

bool isEmpty(BinaryTree tree) {
    if (tree->root == NULL) {
        return true;
    } else {
        return false;
    }
} 
