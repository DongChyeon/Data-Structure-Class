#include <cstdio>
#include "graph.h"

Graph::Graph() { reset(); }
char Graph::getVertex(int i) { return vertices[i]; } 
int Graph::getEdge(int i, int j) { return mat[i][j]; }
void Graph::setEdge(int i, int j, int val) { mat[i][j] = val; }

bool Graph::isEmpty()  { return size==0; }
bool Graph::isFull() { return size>=MAX_VTXS; }

void Graph::reset() {
    size = 0;
    for (int i = 0; i < MAX_VTXS; i++) {
        for (int j = 0; j < MAX_VTXS; j++) {
            setEdge(i, j, 0);
        }
    }
}

void Graph::insertVertex(char name) {
    if (!isFull()) 
        vertices[size++] = name;
    else
        printf("Error: 그래프 정점 개수 초과\n");
}

void Graph::insertEdge(int u, int v) {
    setEdge(u, v, 1);
    setEdge(v, u, 1);
}

void Graph::display() {
    for (int i = 0; i < size; i++) {
        printf("%c ", getVertex(i));
        for (int j = 0; j < size; j++) {
            printf(" %3d", getEdge(i, j));
        }
        printf("\n");
    }
}