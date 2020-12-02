#include "vertexSets.h"

VertexSets::VertexSets(int n) {
    nSets = n;
    for (int i = 0; i < nSets; i++) {
        parent[i] = -1;
    }
}

bool VertexSets::isRoot(int id) { return parent[id] == -1; }

int VertexSets::findSet(int vertice) {
    while (!isRoot(vertice)) vertice = parent[vertice];
    return vertice;
}

void VertexSets::unionSets(int set1, int set2) {
    parent[set1] = set2;
    nSets--;
}