#include "node.h"
#define MAX_VTXS 256

class Graph {
protected:
    int size;
    char vertices[MAX_VTXS];
    Node* mat[MAX_VTXS];
    bool visited[MAX_VTXS];
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
    bool isLinked(int vertice1, int vertice2);
    void DFS(int vertice);
    Node* adjacent(int v);
};