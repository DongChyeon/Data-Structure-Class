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

bool Graph::isEmpty() { return size == 0; }
bool Graph::isFull() { return size >= MAX_VTXS; }
int Graph::getVertex(int i) { return vertices[i]; }

void Graph::insertVertex(int val) {
    if (!isFull()) {
        vertices[size] = val;
        mat[size++] = NULL;
    } else {
        cout << "Error : Graph is full\n";
    }
}

void Graph::insertEdge(int u, int v) {
    mat[u] = new Node(v, mat[u]);
    mat[v] = new Node(u, mat[v]);
}

void Graph::display() {
    for (int i = 0; i < size; i++) {
        cout << "V" << getVertex(i) << " ";
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            cout << "   " << getVertex(v->getId());
        }
        cout << endl;
    }
}

bool Graph::isLinked(int vertice1, int vertice2) {
    for (Node *v = mat[vertice1]; v != NULL; v = v->getLink()) {
        if (v->getId() == vertice2) return true;
    }
    return false;
}

void Graph::DFS(int vertice) {
    visited[vertice] = true;
    cout << "V" << getVertex(vertice) << " ";

    for (Node *v = mat[vertice]; v != NULL; v = v->getLink()) {
        if (visited[v->getId()] == false) DFS(v->getId());
    }
}

void Graph::BFS(int vertice) {
    visited[vertice] = true;
    cout << "V" << getVertex(vertice) << " ";

    queue<int> queue;
    queue.push(vertice);

    while (!queue.empty()) {
        int vertice = queue.front();
        queue.pop();
        for (Node *v = mat[vertice]; v != NULL; v = v->getLink()) {
            int id = v->getId();
            if (!visited[id]) {
                visited[id] = true;
                cout << "V" << getVertex(id) << " ";
                queue.push(id);
            }
        }
    }
}

void Graph::resetVisited() {
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
}