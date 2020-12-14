#include "node.h"
#include "path.h"
#include "vertexSets.h"
#include <queue>
#include <vector>
#define MAX_VTXS 256
#define MAX_EDGES 1024

struct compare {
    bool operator()(Path a, Path b) {
        return a.getWeight() > b.getWeight();
    } 
};

class Graph {
private:
    int size;
    int edgeSize;
    int vertices[MAX_VTXS];
    Node* mat[MAX_VTXS];
    bool visited[MAX_VTXS];
    int label[MAX_VTXS];
    int vtxCount; // The number of vertexes of the connected component to be searched for
    Path path[MAX_EDGES];
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
    void spanningTreeByBFS(int vtx);
    void resetVisited();

    void kruskal(int vtx);
    void prim(int vtx);

    void labelDFS(int vtx, int color);
    void findConnectedComponent();

    void makeRandomGraph(int vtx, int edge);
    bool isDupNode(int vtx1, int vtx2);
    bool startCheck(int next, vector<Path> routes);
};