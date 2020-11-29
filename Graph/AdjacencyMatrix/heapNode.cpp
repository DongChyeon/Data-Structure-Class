#include "heapNode.h"

HeapNode::HeapNode() {}
HeapNode::HeapNode(int key, int vertice1, int vertice2) {
    this->key = key;
    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
}

void HeapNode::setKey(int key, int vertice1, int vertice2) { 
    this->key = key;
    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
}
int HeapNode::getKey() { return key; }
int HeapNode::getVertice1() { return vertice1; }
int HeapNode::getVertice2() { return vertice2; }