#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"
#include "huffmanTree.h"

Queue makeQueue(int n) {
    Queue queue = (Queue) malloc(sizeof(Queue));
    queue->element = (BinaryNode *) malloc(sizeof(BinaryNode) * n);
    queue->size = n;
    queue->index = 0;

    return queue;
}

bool isQueueFull(Queue queue) {
    if (queue->index == queue->size - 1) 
        return true;
    else
        return false;
}

bool isQueueEmpty(Queue queue) {
    if (queue->index == 0)
        return true;
    else
        return false;    
}

void enqueue(Queue queue, BinaryNode elem) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }

    int index = ++queue->index;

    while ((index != 1) && (elem->frequency < queue->element[index / 2]->frequency)) {
        queue->element[index] = queue->element[index / 2];
        index /= 2;
    }
    queue->element[index] = elem;
}

BinaryNode dequeue(Queue queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    BinaryNode ret = queue->element[1];
    queue->element[1] = queue->element[queue->index--];
    int parent = 1;
    int child;

    while (1) {
        child = parent * 2;
        if (child + 1 <= queue->index && queue->element[child]->frequency > queue->element[child + 1]->frequency) {
            child++;
        }

        if (child > queue->index || queue->element[child]->frequency > queue->element[parent]->frequency) break;

        swap(&queue->element[parent], &queue->element[child]);
        parent = child;
    }

    return ret;
}

void printQueue(Queue queue) {
    for (int i = 1; i < queue->index + 1; i++) {
        printf("[%c %d] ", queue->element[i]->value, queue->element[i]->frequency);
    }
    printf("\n");
}

void swap (BinaryNode *a, BinaryNode *b) {
    BinaryNode temp = *a;
    *a = *b;
    *b = temp;
}
