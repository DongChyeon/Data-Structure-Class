#include <cstdio>
#include "graph.h"

Graph::Graph() { reset(); }
char Graph::getVertex(int i) { return vertices[i]; } 
int Graph::getEdge(int i, int j) { return mat[i][j]; }
void Graph::setEdge(int i, int j, int val) { mat[i][j] = val; }

bool Graph::isEmpty()  { return size == 0; }
bool Graph::isFull() { return size >= MAX_VTXS; }

void Graph::reset() {
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < MAX_VTXS; i++) {
        for (int j = 0; j < MAX_VTXS; j++) {
            setEdge(i, j, 0);
        }
    }
    size = 0;
}

void Graph::insertVertex(char name) {
    if (!isFull()) 
        vertices[size++] = name;
    else
        printf("Error: 그래프 정점 개수 초과\n");
}

void Graph::insertEdge(int vertice1, int vertice2) {
    setEdge(vertice1, vertice2, 1);
    setEdge(vertice2, vertice1, 1);
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

bool Graph::isLinked(int vertice1, int vertice2) {
    return getEdge(vertice1, vertice2) != 0; 
}

void Graph::DFS(int vertice) {
    visited[vertice] = true;
    printf("%c ", getVertex(vertice));

    for (int i = 0; i < size; i++) {
        if (isLinked(vertice, i) && visited[i] == false) {
            DFS(i);
        }
    }
}