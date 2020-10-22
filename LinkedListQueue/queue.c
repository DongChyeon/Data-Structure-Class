#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

bool isEmpty(Queue queue) {
    if (queue->front == NULL)
        return true;
    else
        return false;
}

void printQueueItems(Queue queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    list_pointer tnode = queue->front;
    while (tnode != NULL) {
        printf("%d\t", tnode->value);
        tnode = tnode->link;
    }
    printf("\n");
}

Queue makeQueue() {
    Queue queue = (Queue)malloc(sizeof(struct head_pointer));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void enqueue(Queue queue, Element elem) {
    list_pointer ptrNode = (list_pointer)malloc(sizeof(struct list_node));
    if (ptrNode == NULL) {
        printf("::Unable to allocate more memory!!!\n");
    }
    ptrNode->value = elem;
    if (isEmpty(queue)) {
        queue->rear = ptrNode;
        queue->front = ptrNode;
        ptrNode->link = NULL;
    } else {
        Node preNode = queue->rear;
        preNode->link = ptrNode;
        queue->rear = ptrNode;
        ptrNode->link = NULL;
    }
}

Element dequeue(Queue queue) {
    Node node = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");

        return -999;
    }
    else {
        Element elem = node->value;
        queue->front = node->link;
        free(node);

        return elem;
    }
}

void makeQueueEmpty(Queue queue) {
    Node anode = queue->front;
    Node bnode;
    while (anode != NULL) {
        bnode = anode->link;
        free(anode);
        anode = bnode;
    }
    queue->front = NULL;
    queue->rear = NULL;
}

void deleteQueue(Queue queue) {
    makeQueueEmpty(queue);
    free(queue);
}