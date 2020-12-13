#include "queue.h"

int main() {
    Queue<int> queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();
    cout << queue.dequeue() << endl;
    queue.enqueue(6);

    queue.display();

    return 0;
}