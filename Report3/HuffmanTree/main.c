#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
#include "priorityQueue.h"
#include "info.h"

void encoding(char *sentnences);
BinaryTree makeHuffmanTree(char *sentences);
void makeBinaryCode(BinaryNode node, int i, char *code, BinaryInfo info);

void encoding(char *sentences) {
    BinaryTree tree = makeHuffmanTree(sentences);
    char binaryCode[100];
    BinaryInfo info = makeInfo();

    makeBinaryCode(tree->root, -1, binaryCode, info);

    for (int i = 0; i < strlen(sentences); i++) {
        printCode(info, sentences[i]);
    }

    deleteInfo(info);
}

BinaryTree makeHuffmanTree(char *sentences) {
    int index = 0;
    
    BinaryTree tree = makeTree();
    BinaryNode characters[128];

    for (int i = 0; i < strlen(sentences); i++) {
        bool skipOuter = false;
        char ch = sentences[i];

        for (int j = 0; j < index; j++) {
            if (characters[j]->value == ch) {
                characters[j]->frequency++;
                skipOuter = true;
                break;
            }
        }

        if (skipOuter) continue;

        characters[index] = makeNode(sentences[i], 1, NULL, NULL);
        index++;
    }

    Queue queue = makeQueue(128);

    for (int i = 0; i < index; i++) {
        enqueue(queue, characters[i]);
    }

    while (queue->index >= 2) {
        BinaryNode right = dequeue(queue);
        BinaryNode left = dequeue(queue);
        BinaryNode center = makeNode(NULL, right->frequency + left->frequency, left, right);
        enqueue(queue, center);
    }

    setRoot(tree, dequeue(queue));

    return tree;
}

void makeBinaryCode(BinaryNode node, int i, char *code, BinaryInfo info) {
    if (node != NULL) {
        i++;
        code[i] = '1';
        makeBinaryCode(node->left, i, code, info);
        code[i] = '0';
        makeBinaryCode(node->right, i, code, info);
        code[i] = '\0';

        if (node->left == NULL && node->right == NULL) {
            node->code = code;
            printf("%c : %s\n", node->value, node->code);
            addItem(info, node->value, node->code);
        }
    }

}

int main() {
    char sentences[256];
    
    printf("Please enter the sentence : ");
    scanf_s("%[^\n]", &sentences, sizeof(sentences));

    encoding(sentences);

    return 0; 
}