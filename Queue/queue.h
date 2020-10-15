#include <stdbool.h>

typedef struct {
    int *element;
    int max_size;
    int front,rear;
    bool last_oper;
} Queue;

Queue *create(int n);
bool isFull(Queue *queue);
void enqueue(Queue *queue, int elem);
bool isEmpty(Queue *queue);
int pop(Queue *queue);
void printQueue(Queue *queue);