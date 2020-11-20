#include <stdio.h>
#include "heap.h"

int main() {
    Heap heap = makeHeap(10);
    insertElem(heap, 5);
    insertElem(heap, 4);
    insertElem(heap, 1);
    insertElem(heap, 3);
    insertElem(heap, 2);

    printHeap(heap);
    printf("deleted : %d\n", deleteElem(heap));
    printHeap(heap);
    printf("deleted : %d\n", deleteElem(heap));
    printHeap(heap);
    printf("deleted : %d\n", deleteElem(heap));
    printHeap(heap);

    return 0;
}