#include <iostream>
#include <queue>
#define MAX_VTXS 256
using namespace std;

class Graph {
private:
    int size;
    int vertices[MAX_VTXS];
    int mat[MAX_VTXS][MAX_VTXS];
    bool visited[MAX_VTXS];
public:
    Graph();
    int getVertex(int i);
    int getEdge(int i, int j);
    void setEdge(int i, int j, int val);

    bool isEmpty();
    bool isFull();
    void reset();

    void insertVertex(int val);
    void insertEdge(int vertice1, int vertice2, int weight);
    void display();

    bool hasEdge(int vertice1, int vertice2);
    bool isLinked(int vertice1, int vertice2);
    void DFS(int vertice);
    void BFS(int vertice);
    void resetVisited();

    void kruskal();
};