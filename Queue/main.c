#include <stdio.h>
#include "queue.h"

int main() {
    Queue *queue = create(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);
    
    enqueue(queue, 5);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    enqueue(queue, 6);
    printQueue(queue);

    enqueue(queue, 7);
    printQueue(queue);

    return 0;
}