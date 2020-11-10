#include <stdbool.h>

#ifndef _BINARY_TREE_
#define _BINARY_TREE_

typedef int Element;
typedef struct binaryTree* BinaryTree;
typedef struct binaryNode* BinaryNode;
typedef struct binaryTree {
    BinaryNode root;
} binaryTree;
typedef struct binaryNode {
    Element value;
    BinaryNode left;
    BinaryNode right;
} binaryNode;

BinaryNode makeNode(int elem, BinaryNode left, BinaryNode right);
void setData(BinaryNode node, int elem);
void setLeft(BinaryNode node, BinaryNode left);
void setRight(BinaryNode node, BinaryNode right);
Element getData(BinaryNode node);

BinaryTree makeTree();
void setRoot(BinaryTree tree, BinaryNode root);
BinaryNode getRoot(BinaryTree tree);
bool isEmpty(BinaryTree tree);

#endif