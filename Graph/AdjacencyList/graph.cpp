#include "graph.h"

Graph::Graph() {
    size = 0;
}
Graph::~Graph() {
    reset();
}
void Graph::reset() {
    for (int i = 0; i < size; i++) {
        if (mat[i] != NULL)
            delete mat[i];
    }
    size = 0;
}
bool Graph::isEmpty() {
    return size == 0;
}
bool Graph::isFull() {
    return size >= MAX_VTXS;
}
char Graph::getVertex(int i) {
    return vertices[i];
}
void Graph::insertVertex(char val) {
    if (!isFull()) {
        vertices[size] = val;
        mat[size++] = NULL;
    } else {
        printf("Error : Graph is full\n");
    }
}
void Graph::insertEdge(int u, int v) {
    mat[u] = new Node(v, mat[u]);
    mat[v] = new Node(u, mat[v]);
}
void Graph::display() {
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%c ", getVertex(i));
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            printf("    %c", getVertex(v->getId()));
            printf("%3d", v->getId());
        }
        printf("\n");
    }
}
Node* Graph::adjacent(int v) {
    return mat[v];
}