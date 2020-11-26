#include "node.h"
#define MAX_VTXS 256

class Graph {
protected:
    int size;
    char vertices[MAX_VTXS];
    Node* mat[MAX_VTXS];
public:
    Graph();
    ~Graph();
    void reset();
    bool isEmpty();
    bool isFull();
    char getVertex(int i);
    void insertVertex(char val);
    void insertEdge(int u, int v);
    void display();
    Node* adjacent(int v);
};