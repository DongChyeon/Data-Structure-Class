#include <stdbool.h>

#ifndef _QUEUE_
#define _QUEUE

typedef struct {
    int *element;
    int size;
    int front,rear;
    bool last_oper;
} queue;
typedef queue* Queue;

Queue create(int n);
bool isFull(Queue queue);
void enqueue(Queue queue, int elem);
int dequeue(Queue queue);
bool isEmpty(Queue queue);
int pop(Queue queue);
void printQueue(Queue queue);

#endif