#include "node.h"
#include <queue>
#define MAX_VTXS 256

class Graph {
private:
    int size;
    int vertices[MAX_VTXS];
    Node* mat[MAX_VTXS];
    bool visited[MAX_VTXS];
public:
    Graph();
    ~Graph();
    void reset();
    bool isEmpty();
    bool isFull();
    int getVertex(int i);
    void insertVertex(int val);
    void insertEdge(int u, int v, int weight);
    void printGraph();
    bool isLinked(int vertice1, int vertice2);
    void DFS(int vertice);
    void BFS(int vertice);
    void resetVisited();
};