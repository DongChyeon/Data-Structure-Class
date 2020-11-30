#include <iostream>

class HeapNode {
private:
    int key;
    int vtx1;
    int vtx2;
public:
    HeapNode();
    HeapNode(int key, int vtx1, int vtx2);
    void setKey(int key, int vtx1, int vtx2);
    int getKey();
    int getVtx1();
    int getVtx2();
};