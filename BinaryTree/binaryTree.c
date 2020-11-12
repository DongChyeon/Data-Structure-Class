#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "queue.h"

BinaryNode makeNode(int elem, BinaryNode left, BinaryNode right) {
    BinaryNode node = (BinaryNode)malloc(sizeof(struct binaryNode));
    node->value = elem;
    node->left = left;
    node->right = right;

    return node;
}

BinaryTree makeTree(BinaryNode root) {
    BinaryTree tree = (BinaryTree)malloc(sizeof(struct binaryTree));

    return tree;
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
        printf("[%d] ", node->value);
        inorder(node->right);
    }
}

void preorder(BinaryNode node) {
    if (node != NULL) {
        printf("[%d] ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(BinaryNode node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("[%d] ", node->value);
    }
}

void levelorder(BinaryNode node) {
    Queue queue = makeQueue();
    enqueue(queue, node);
    while (!isQueueEmpty(queue)) {
        BinaryNode temp = dequeue(queue);
        if (temp != NULL) {
            printf("[%d] ", temp->value);
            enqueue(queue, temp->left);
            enqueue(queue, temp->right);
        }
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

void printLevelorder(BinaryTree tree) {
    if (isTreeEmpty(tree)) {
        printf("Tree is empty\n");
    }

    printf("levelorder\n");
    levelorder(tree->root);
    printf("\n");
}