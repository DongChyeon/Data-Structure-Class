#include <iostream>

class HeapNode {
private:
    int key;
    int vertice1;
    int vertice2;
public:
    HeapNode();
    HeapNode(int key, int vertice1, int vertice2);
    void setKey(int key, int vertice1, int vertice2);
    int getKey();
    int getVertice1();
    int getVertice2();
};