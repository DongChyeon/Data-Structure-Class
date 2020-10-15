#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue *create(int n) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->element = (int *) malloc(sizeof(int) * n);
    queue->max_size = n;
    queue->front = -1;
    queue->rear = 0;
    queue->last_oper = true;

    return queue;
}

bool isFull(Queue *queue) {
    if (queue->front == queue->rear && !queue->last_oper)
        return true;
    else
        return false;
}

void enqueue(Queue *queue, int elem) {
    if (!isFull(queue)) {
        queue->rear = queue->rear + 1 % (queue->max_size - 1);
        queue->element[queue->rear - 1] = elem;
    }
}

bool isEmpty(Queue *queue) {
    if (queue->front == queue->rear && queue->last_oper)
        return true;
    else
        return false;
}

int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        queue->front = queue->front + 1 % (queue->max_size - 1);
        return queue->element[queue->front - 1];
    }
}

void printQueue(Queue *queue) {
    for (int i = queue->front + 1; i < queue->rear; i++) {
        printf("%d ", queue->element[i]);
    }
    printf("\n");
}