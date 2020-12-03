#include "node.h"
#include "path.h"
#include "vertexSets.h"
#include <queue>
#define MAX_VTXS 256

struct compare {
    bool operator()(Path a, Path b) {
        return a.getKey() > b.getKey();
    } 
};

class Graph {
private:
    int size;
    int edgeCount;
    int vertices[MAX_VTXS];
    Node* mat[MAX_VTXS];
    bool visited[MAX_VTXS];
    int label[MAX_VTXS];

    int prev[MAX_VTXS / 2];
    int next[MAX_VTXS / 2];
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
    void adjSearch(int vtx);
    void BFS(int vtx);
    void resetVisited();

    void kruskal(int vtx);
    void prim(int vtx);

    void labelDFS(int vtx, int color);
    void findConnectedComponent();

    void makeRandomGraph(int vtx, int edge);
    void printEdge();

    bool dupNodeCheck(int vtx1, int vtx2);
};