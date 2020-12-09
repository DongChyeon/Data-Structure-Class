#include "maxHeap.h"

MinHeap::MinHeap() { size = 0; }
bool MinHeap::isEmpty() { return size == 0; }
bool MinHeap::isFull() { return size == MAX_ELEMENT - 1;}
int MinHeap::getParent(int id) { return elem[id / 2]; }
int MinHeap::getLeft(int id) { return elem[id * 2]; }
int MinHeap::getRight(int id) { return elem[id * 2 + 1];}

void MinHeap::insert(int val) {
    if (isFull()) {
        cout << "Heap is full\n";
        return;
    }

    int id = ++size;

    while (id != 1 && val > getParent(id)) {
        elem[id] = getParent(id);
        id /= 2;
    }
    elem[id] = val;
}

int MinHeap::remove() {
    if (isEmpty()) {
        cout << "Heap is empty\n";
        return -1;
    }
    int ret = elem[1];
    int last = elem[size--];
    int parent = 1;
    int child = 2;
    while (child <= size) {
        if (child < size && getLeft(parent) < getRight(parent)) 
            child++;
        if (last >= elem[child]) 
            break;
        elem[parent] = elem[child];
        parent = child;
        child *= 2;
    }
    elem[parent] = last;

    return ret; 
}

void MinHeap::printHeap() {
    for (int i = 1, level = 1; i <= size; i++) {
        if (i == level) {
            cout << endl;
            level *= 2;
        }
        cout << elem[i] << " ";
    }
    cout << endl;
}