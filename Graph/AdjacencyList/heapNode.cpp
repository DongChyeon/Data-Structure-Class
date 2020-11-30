#include "heapNode.h"

HeapNode::HeapNode() {}
HeapNode::HeapNode(int key, int vtx1, int vtx2) {
    this->key = key;
    this->vtx1 = vtx1;
    this->vtx2 = vtx2;
}

void HeapNode::setKey(int key, int vtx1, int vtx2) { 
    this->key = key;
    this->vtx1 = vtx1;
    this->vtx2 = vtx2;
}
int HeapNode::getKey() { return key; }
int HeapNode::getVtx1() { return vtx1; }
int HeapNode::getVtx2() { return vtx2; }