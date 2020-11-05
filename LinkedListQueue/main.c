#include <stdio.h>
#include "queue.h"

int main() {
    Queue queue = makeQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueueItems(queue);

    dequeue(queue);
    dequeue(queue);
    printQueueItems(queue);
    dequeue(queue);
    printQueueItems(queue);

    enqueue(queue, 1);
    enqueue(queue, 3);
    enqueue(queue, 5);
    printQueueItems(queue);

    return 0;
}