#include <stdbool.h>

#ifndef _BINARY_TREE_
#define _BINARY_TREE_

typedef struct binaryTree* BinaryTree;
typedef struct binaryNode* BinaryNode;
typedef struct binaryTree {
    BinaryNode root;
} binaryTree;
typedef struct binaryNode {
    char value;
    BinaryNode left;
    BinaryNode right;
} binaryNode;

BinaryNode makeNode(char elem, BinaryNode left, BinaryNode right);

BinaryTree makeTree();
bool isTreeEmpty(BinaryTree tree);
void setRoot(BinaryTree tree, BinaryNode root);

void inorder(BinaryNode node);
void preorder(BinaryNode node);
void postorder(BinaryNode node);
void levelorder(BinaryNode node);

#endif