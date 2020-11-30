#include "node.h"
#include "minHeap.h"
#include "vertexSets.h"
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
    int getVertex(int id);
    int getEdge(int vtx1, int vtx2);
    void insertVertex(int val);
    void insertEdge(int vtx1, int vtx2, int weight);
    void printGraph();
    bool isLinked(int vtx1, int vtx2);

    void DFS(int vtx);
    void BFS(int vtx);
    void resetVisited();

    void kruskal();
    void prim(int vtx);
};