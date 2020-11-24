#include <stdbool.h>

#ifndef _BINARY_TREE_
#define _BINARY_TREE_

typedef struct binaryNode* BinaryNode;
typedef struct binaryTree* BinaryTree;
typedef struct binaryNode {
    char value;
    char *code;
    int frequency;
    BinaryNode left;
    BinaryNode right;
} binaryNode;
typedef struct binaryTree {
    BinaryNode root;
} binaryTree;

BinaryNode makeNode(char elem, int frequency, BinaryNode left, BinaryNode right);

BinaryTree makeTree();
bool isLeaf(BinaryNode node);
bool isTreeEmpty(BinaryTree tree);
void setRoot(BinaryTree tree, BinaryNode root);

void inorder(BinaryNode node);
void preorder(BinaryNode node);
void postorder(BinaryNode node);

void printInorder(BinaryTree tree);
void printPreorder(BinaryTree tree);
void printPostorder(BinaryTree tree);

#endif