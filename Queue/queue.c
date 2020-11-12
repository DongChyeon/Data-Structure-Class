#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue create(int n) {
    Queue queue = (Queue) malloc(sizeof(queue));
    queue->element = (int *) malloc(sizeof(int) * n);
    queue->size = n;
    queue->front = 0;
    queue->rear = 0;
    queue->last_oper = true;

    return queue;
}

bool isFull(Queue queue) {
    if (queue->front == queue->rear && !queue->last_oper)
        return true;
    else
        return false;
}

void enqueue(Queue queue, int elem) {
    if (!isFull(queue)) {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->element[queue->rear] = elem;
        queue->last_oper = false;
    }
}

bool isEmpty(Queue queue) {
    if (queue->front == queue->rear && queue->last_oper)
        return true;
    else
        return false;
}

int dequeue(Queue queue) {
    if (!isEmpty(queue)) {
        queue->front = (queue->front + 1) % queue->size;
        queue->last_oper = true;
        return queue->element[queue->front];
    }
}

void printQueue(Queue queue) {
    if (queue->front > queue->rear && queue->rear == 0 && queue->last_oper) {
        for (int i = queue->front + 1; i < queue->size; i++) {
            printf("%d ", queue->element[i]);
        }
        printf("%d", queue->element[0]);
    } else if (queue->front > queue->rear) {
        for (int i = queue->front + 1; i < queue->size; i++) {
            printf("%d ", queue->element[i]);
        }
        for (int i = 0; i < queue->front; i++) {
            printf("%d ", queue->element[i]);
        }
    } else if (isFull(queue)) {
        for (int i = queue->front + 1; i < queue->size; i++) {
            printf("%d ", queue->element[i]);
        }
        for (int i = 0; i < queue->front + 1; i++) {
            printf("%d ", queue->element[i]);
        }
        printf("\n");
    } else {
        for (int i = queue->front + 1; i < queue->rear + 1; i++) {
            printf("%d ", queue->element[i]);
        }
    }
}