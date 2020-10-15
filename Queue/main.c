#include <stdio.h>
#include "queue.h"

int main() {
    Queue *queue = create(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);

    return 0;
}