#include <stdbool.h>
#include "info.h"

#ifndef _HUFFMAN_TREE_
#define _HUFFMAN_TREE_

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
void encoding(char *sentnences, BinaryTree tree, char *code);
void decoding(char *code, BinaryTree tree);
BinaryTree makeHuffmanTree(char *sentences);
void makeBinaryCode(BinaryNode node, int i, char *code, BinaryInfo info);

#endif