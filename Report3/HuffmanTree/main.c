#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
#include "stack.h"

BinaryTree makeHuffmanTree(char *setences);

BinaryTree makeHuffmanTree(char *setences) {
    BinaryTree tree = makeTree();
    BinaryNode node;

    return tree;
}

int main() {
    char sentences[256];
    BinaryNode characters[128];
    printf("Please enter the sentence : ");
    scanf_s("%s", &sentences, sizeof(sentences));

    BinaryTree tree = makeHuffmanTree(sentences);

    printInorder(tree);
    printPreorder(tree);
    printPostorder(tree);
    printLevelorder(tree);

    return 0; 
}