#include <stdbool.h>

#ifndef _HEAP_
#define _HEAP_

typedef struct {
    int *element;
    int size;
    int index;
} heap;
typedef heap* Heap;

Heap makeHeap(int n);
bool isFull(Heap heap);
bool isEmtpy(Heap heap);
void insertElem(Heap heap, int elem);
int deleteElem(Heap heap);
void printHeap(Heap heap);
void swap (int *a, int *b);

#endif