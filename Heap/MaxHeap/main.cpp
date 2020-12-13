#include "maxHeap.h"

int main() {
    MinHeap heap;

	int arr[13] = { 30, 10, 25, 15, 80, 35, 1, 45, 89, 90, 11, 6, 66 };
	for (int i = 0; i < 13; i++) {
		heap.insert(arr[i]);
	}
	heap.printHeap();
	
    return 0;
}