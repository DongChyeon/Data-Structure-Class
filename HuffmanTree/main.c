#include <stdio.h>
#include <string.h>
#include "huffmanTree.h"

int main() {
    char sentences[512];
    char code[5120] = "";
    
    printf("Please enter the sentence : ");
    scanf_s("%[^\n]", &sentences, sizeof(sentences));
    BinaryTree tree = makeHuffmanTree(sentences);

    printf("\nAfter Encoding\n");
    encoding(sentences, tree, code);
    printf("\nAfter Decoding\n");
    decoding(code, tree);
    printf("\n\nIn ASCII Code : %d bits\n", strlen(sentences) * 7);
    printf("In Huffman Code : %d bits", strlen(code));

    return 0; 
}