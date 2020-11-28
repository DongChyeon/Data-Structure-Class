#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "huffmanTree.h"
#include "priorityQueue.h"
#include "info.h"

BinaryNode makeNode(char elem, int frequency, BinaryNode left, BinaryNode right) {
    BinaryNode node = (BinaryNode)malloc(sizeof(struct binaryNode));
    node->value = elem;
    node->frequency = frequency;
    node->left = left;
    node->right = right;

    return node;
}

BinaryTree makeTree() {
    BinaryTree tree = (BinaryTree)malloc(sizeof(struct binaryTree));

    return tree;
}

bool isLeaf(BinaryNode node) {
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
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

void encoding(char *sentences, BinaryTree tree, char *code) {
    char binaryCode[100];
    BinaryInfo info = makeInfo();

    makeBinaryCode(tree->root, -1, binaryCode, info);

    for (int i = 0; i < info->size; i++) {
        printf("%c : %s\n", info->items[i].character, info->items[i].code);
    }

    for (int i = 0; i < strlen(sentences); i++) {
        printf("%s", searchCode(info, sentences[i]));
        strcat_s(code, sizeof(char) * 1024, searchCode(info, sentences[i]));
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
            temp = temp->left;
        } else if (code[i] == '1') {
            temp = temp->right;
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
        code[i] = '0';
        makeBinaryCode(node->left, i, code, info);
        code[i] = '1';
        makeBinaryCode(node->right, i, code, info);
        code[i] = '\0';

        if (isLeaf(node)) {
            node->code = code;
            addItem(info, node->value, node->code);
        }
    }
}