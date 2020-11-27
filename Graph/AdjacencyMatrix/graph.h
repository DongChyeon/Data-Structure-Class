#include <cstdio>
#define MAX_VTXS 256

class Graph {
protected:
    int size;
    char vertices[MAX_VTXS];
    int mat[MAX_VTXS][MAX_VTXS];
    bool visited[MAX_VTXS];
public:
    Graph();
    char getVertex(int i);
    int getEdge(int i, int j);
    void setEdge(int i, int j, int val);

    bool isEmpty();
    bool isFull();
    void reset();

    void insertVertex(char name);
    void insertEdge(int vertice1, int vertice2);
    void display();

    bool isLinked(int vertice1, int vertice2);
    void DFS(int vertice);
};