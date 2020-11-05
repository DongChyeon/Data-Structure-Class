#include <stdio.h>
#include "queue.h"

int main() {
    int a, b;

    Queue *queue = create(10);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 14);

    a = dequeue(queue);
    enqueue(queue, -3);
    b = dequeue(queue);
    printf("a = %d, b = %d, a + b + dequeue(queue) = %d", a, b, a + b + dequeue(queue));

    return 0;
}