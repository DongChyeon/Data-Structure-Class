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

int Graph::getVertex(int id) { return vertices[id]; }
int Graph::getEdge(int vertice1, int vertice2) {
    int vertex = getVertex(vertice1);
    for (Node *v = mat[vertex]; v != NULL; v = v->getLink()) {
        if (v->getId() == vertice2) return v->getWeight();
    }
}

void Graph::insertVertex(int val) {
    if (!isFull()) {
        vertices[size] = val;
        mat[size++] = NULL;
    } else {
        cout << "Error : Graph is full\n";
    }
}

void Graph::insertEdge(int vertice1, int vertice2, int weight) {
    mat[vertice1] = new Node(vertice2, mat[vertice1], weight);
    mat[vertice2] = new Node(vertice1, mat[vertice2], weight);
}

void Graph::printGraph() {
    for (int i = 0; i < size; i++) {
        cout << "V" << getVertex(i) << " ";
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            cout << "   V" << getVertex(v->getId()) << '[' << v->getWeight() << ']';
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
    cout << endl;
}

void Graph::resetVisited() {
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
}

void Graph::kruskal() {
    MinHeap heap;
    for (int i = 0; i < size; i++) {
        int vertice1 = getVertex(i);
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            cout << vertice1 << " " << v->getId() << " [" << v->getWeight() << "]\n";
            heap.insert(v->getWeight(), vertice1, v->getId());
        }
    }

    VertexSets set(size);
    int edgeAccepted = 0;
    cout << "Kruskal Algorithm" << endl;
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

void Graph::prim(int vertice) {
    bool selected[MAX_VTXS];
    int dist[MAX_VTXS];
    int prev = vertice;
    for (int i = 0; i < size; i++) {
        dist[i] = 9999;
        selected[i] = false;
    }
    dist[vertice] = 0;

    for (int i = 0; i < size; i++) {
        int min = getMinVertex(selected, dist);

        selected[min] = true;
        if (dist[min] == 9999) return;

        cout << "Add Edge : " << prev << " - " << getVertex(min) << endl;
        prev = getVertex(min);

        for (int i = 0; i < size; i++) {
            if (getEdge(min, i) != 9999) {
                if (!selected[i] && getEdge(min, i) < dist[i])
                    dist[i] = getEdge(min, i);
            }
        }
    }
    cout << endl;
}

int Graph::getMinVertex(bool* selected, int* dist) {
    int minVertex = 0;
    int minDist = 9999;
    for (int i = 0; i < size; i++) {
        if (!selected[i] && dist[i] < minDist) {
            minDist = dist[i];
            minVertex = i;
        }
    }

    return minVertex;
}