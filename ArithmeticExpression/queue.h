#include <stdbool.h>
#include "binaryTree.h"

#ifndef _QUEUE_
#define _QUEUE_

typedef struct list_node* list_pointer;
typedef struct head_pointer* LinkedList;
typedef LinkedList Queue;
typedef list_pointer Node;
typedef struct list_node {
    BinaryNode elem;
    list_pointer link;
} list_node;
typedef struct head_pointer {
    list_pointer front;
    list_pointer rear;
} head_pointer;

bool isQueueEmpty(Queue queue);
void printQueueItems(Queue queue);
Queue makeQueue();
void enqueue(Queue queue, BinaryNode elem);
BinaryNode dequeue(Queue queue);
void makeQueueEmpty(Queue queue);
void deleteQueue(Queue queue);

#endif