#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
#include "priorityQueue.h"

BinaryTree makeHuffmanTree(char *sentences);

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

int main() {
    char sentences[256];
    
    printf("Please enter the sentence : ");
    scanf_s("%[^\n]", &sentences, sizeof(sentences));

    BinaryTree tree = makeHuffmanTree(sentences);

    printInorder(tree);
    printPreorder(tree);
    printPostorder(tree);

    return 0; 
}