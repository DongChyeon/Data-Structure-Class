#include <stdbool.h>
#include "binaryTree.h"

#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

typedef struct {
    BinaryNode *element;
    int size;
    int index;
} queue;
typedef queue* Queue;

Queue makeQueue(int n);
bool isQueueFull(Queue queue);
bool isQueueEmpty(Queue queue);
bool contains(Queue queue, char elem);
void enqueue(Queue queue, BinaryNode elem);
BinaryNode dequeue(Queue queue);
void printQueue(Queue queue);
void swap (BinaryNode *a, BinaryNode *b);

#endif