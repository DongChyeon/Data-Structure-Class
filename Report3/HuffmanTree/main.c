#include <stdio.h>
#include "huffmanTree.h"

int main() {
    char sentences[512];
    char code[2048] = "";
    
    printf("Please enter the sentence : ");
    scanf_s("%[^\n]", &sentences, sizeof(sentences));
    BinaryTree tree = makeHuffmanTree(sentences);

    printf("\nAfter Encoding\n");
    encoding(sentences, tree, code);
    printf("\nAfter Decoding\n");
    decoding(code, tree);

    return 0; 
}