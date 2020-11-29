#include "graph.h"
#include "vertexsets.h"
#include "minHeap.h"

Graph::Graph() { reset(); }
int Graph::getVertex(int i) { return vertices[i]; } 
int Graph::getEdge(int i, int j) { return mat[i][j]; }
void Graph::setEdge(int i, int j, int val) { mat[i][j] = val; }

bool Graph::isEmpty()  { return size == 0; }
bool Graph::isFull() { return size >= MAX_VTXS; }

void Graph::reset() {
    for (int i = 0; i < MAX_VTXS; i++) {
        for (int j = 0; j < MAX_VTXS; j++) {
            setEdge(i, j, 0);
        }
    }
    size = 0;
}

void Graph::insertVertex(int val) {
    if (!isFull()) 
        vertices[size++] = val;
    else
        cout << "Error: graph's edge is full\n";
}

void Graph::insertEdge(int vertice1, int vertice2, int weight) {
    setEdge(vertice1, vertice2, weight);
}

void Graph::display() {
    for (int i = 0; i < size; i++) {
        cout << getVertex(i) << " ";
        for (int j = 0; j < size; j++) {
            cout << " " << getEdge(i, j);
        }
        cout << endl;
    }
}

bool Graph::hasEdge(int vertice1, int vertice2) {
    return (getEdge(vertice1, vertice2) > 0);
}

bool Graph::isLinked(int vertice1, int vertice2) {
    return getEdge(vertice1, vertice2) != 0; 
}

void Graph::DFS(int vertice) {
    visited[vertice] = true;
    cout << "V" << getVertex(vertice) << " ";

    for (int i = 0; i < size; i++) {
        if (isLinked(vertice, i) && visited[i] == false) {
            DFS(i);
        }
    }
}

void Graph::BFS(int vertice) {
    visited[vertice] = true;
    cout << "V" << getVertex(vertice) << " ";

    queue<int> queue;
    queue.push(vertice);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for (int i = 0; i < size; i++) {
            if (isLinked(v, i) && visited[i] == false) {
                visited[i] = true;
                cout << "V" << getVertex(i) << " ";
                queue.push(i);
            }
        }
    }
}

void Graph::resetVisited() {
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
}

void Graph::kruskal() {
    MinHeap heap;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (hasEdge(i, j)) heap.insert(getEdge(i, j), i, j);
        }
    }

    VertexSets set(size);
    int edgeAccepted = 0;
    while (edgeAccepted < size - 1) {
        HeapNode node = heap.remove();
        int set1 = set.findSet(node.getVertice1());
        int set2 = set.findSet(node.getVertice2());
        if (set1 != set2) {
            cout << "Add Edge : " << getVertex(node.getVertice1()) << " - " << getVertex(node.getVertice2()) << " cost : " << node.getKey() << endl;
            set.unionSets(set1, set2);
            edgeAccepted++;
        }
    }
}