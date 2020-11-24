#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
#include "priorityQueue.h"
#include "info.h"

void encoding(char *sentnences, BinaryTree tree);
void decoding(char *code, BinaryTree tree);
BinaryTree makeHuffmanTree(char *sentences);
void makeBinaryCode(BinaryNode node, int i, char *code, BinaryInfo info);

void encoding(char *sentences, BinaryTree tree) {
    char binaryCode[100];
    BinaryInfo info = makeInfo();

    makeBinaryCode(tree->root, -1, binaryCode, info);

    for (int i = 0; i < info->size; i++) {
        printf("%c : %s\n", info->items[i].character, info->items[i].code);
    }

    for (int i = 0; i < strlen(sentences); i++) {
        printCode(info, sentences[i]);
    }
    printf("\n");
}

void decoding(char *code, BinaryTree tree) {
    BinaryNode temp = tree->root;

    for (int i = 0; i < strlen(code) + 1; i++) {
        if (isLeaf(temp)) {
            printf("%c", temp->value);
            temp = tree->root;
        }

        if (code[i] == '0') {
            temp = temp->right;
        } else if (code[i] == '1') {
            temp = temp->left;
        }
    }
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

        if (isLeaf(node)) {
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
    BinaryTree tree = makeHuffmanTree(sentences);

    encoding(sentences, tree);
    char codes[1000] = "00111101100010000111110101011111000110000101101111101011001111100100110001001100111011110101100011100101010010";
    decoding(codes, tree);

    return 0; 
}