#include "minHeap.h"

MinHeap::MinHeap() { size = 0; }
bool MinHeap::isEmpty() { return size == 0; }
bool MinHeap::isFull() { return size == MAX_ELEMENT - 1;}
HeapNode& MinHeap::getParent(int id) { return node[id / 2]; }
HeapNode& MinHeap::getLeft(int id) { return node[id * 2]; }
HeapNode& MinHeap::getRight(int id) { return node[id * 2 + 1];}

void MinHeap::insert(int key, int vtx1, int vtx2) {
    if (isFull()) return;
    int id = ++size;
    while (id != 1 && key < getParent(id).getKey()) {
        node[id] = getParent(id);
        id /= 2;
    }
    node[id].setKey(key, vtx1, vtx2);
}

HeapNode MinHeap::remove() {
    if (isEmpty()) return HeapNode();
    HeapNode root = node[1];
    HeapNode last = node[size--];
    int parent = 1;
    int child = 2;
    while (child <= size) {
        if (child < size && getLeft(parent).getKey() > getRight(parent).getKey()) 
            child++;
        if (last.getKey() <= node[child].getKey()) 
            break;
        node[parent] = node[child];
        parent = child;
        child *= 2;
    }
    node[parent] = last;

    return root; 
}