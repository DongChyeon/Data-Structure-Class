#include <cstdio>
#define MAX_VTXS 256

class Graph {
protected:
    int size;
    char vertices[MAX_VTXS];
    int mat[MAX_VTXS][MAX_VTXS];
public:
    Graph();
    char getVertex(int i);
    int getEdge(int i, int j);
    void setEdge(int i, int j, int val);

    bool isEmpty();
    bool isFull();
    void reset();

    void insertVertex(char name);
    void insertEdge(int u, int v);
    void display();
};