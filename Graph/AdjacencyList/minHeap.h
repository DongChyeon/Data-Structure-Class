#include "heapNode.h"
#define MAX_ELEMENT 200

class MinHeap {
private:
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MinHeap();
    bool isEmpty();
    bool isFull();
    HeapNode& getParent(int id);
    HeapNode& getLeft(int id);
    HeapNode& getRight(int id);
    void insert(int key, int vertice1, int vertice2);
    HeapNode remove();
};