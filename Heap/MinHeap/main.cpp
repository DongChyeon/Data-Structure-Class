#include "minHeap.h"

int main() {
    MinHeap heap;

	heap.insert(1);
	heap.insert(6);
	heap.insert(5);
	heap.insert(3);
	heap.insert(7);
	heap.insert(2);
	heap.printHeap();

	heap.remove();
	heap.printHeap();

    return 0;
}