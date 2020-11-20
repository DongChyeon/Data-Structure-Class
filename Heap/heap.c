#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

Heap makeHeap(int n) {
    Heap heap = (Heap) malloc(sizeof(heap));
    heap->element = (int *) malloc(sizeof(int) * n);
    heap->size = n;
    heap->index = 0;

    return heap;
}

bool isFull(Heap heap) {
    if (heap->index == heap->size - 1) 
        return true;
    else
        return false;
}

bool isEmpty(Heap heap) {
    if (heap->index == 0)
        return true;
    else
        return false;    
}

void insertElem(Heap heap, int elem) {
    if (isFull(heap)) {
        printf("Heap is full\n");
        return;
    }

    int index = ++heap->index;

    while ((index != 1) && (elem < heap->element[index / 2])) {
        heap->element[index] = heap->element[index / 2];
        index /= 2;
    }
    heap->element[index] = elem;
}

int deleteElem(Heap heap) {
    if (isEmpty(heap)) {
        printf("Heap is empty\n");
        return -1;
    }

    int ret = heap->element[1];
    heap->element[1] = heap->element[heap->index--];
    int parent = 1;
    int child;

    while (1) {
        child = parent * 2;
        if (child + 1 <= heap->index && heap->element[child] > heap->element[child + 1]) {
            child++;
        }

        if (child > heap->index || heap->element[child] > heap->element[parent]) break;

        swap(&heap->element[parent], &heap->element[child]);
        parent = child;
    }

    return ret;
}

void printHeap(Heap heap) {
    for (int i = 1; i < heap->index + 1; i++) {
        printf("[%d] ", heap->element[i]);
    }
    printf("\n");
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
