#include <iostream>
#define MAX_ELEMENT 1024
using namespace std;

class MinHeap {
private:
    int elem[MAX_ELEMENT];
    int size;
public:
    MinHeap();
    bool isEmpty();
    bool isFull();
    int getParent(int id);
    int getLeft(int id);
    int getRight(int id);
    void insert(int val);
    int remove();
};