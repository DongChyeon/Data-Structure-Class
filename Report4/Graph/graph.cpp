#include "graph.h"

Graph::Graph() {
    size = 0;
    edgeCount = 0;
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
    edgeCount = 0;
}

bool Graph::isEmpty() { return size == 0; }
bool Graph::isFull() { return size >= MAX_VTXS; }

int Graph::getVertex(int id) { return vertices[id]; }
int Graph::getEdge(int vtx1, int vtx2) {
    for (Node *v = mat[vtx1]; v != NULL; v = v->getLink()) {
        if (v->getId() == vtx2) return v->getWeight();
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

void Graph::insertEdge(int vtx1, int vtx2, int weight) {
    mat[vtx1] = new Node(vtx2, mat[vtx1], weight);
    prev[edgeCount] = vtx1;

    mat[vtx2] = new Node(vtx1, mat[vtx2], weight);
    prev[edgeCount] = vtx2;

    edgeCount++;
}

void Graph::printGraph() {
    for (int i = 0; i < size; i++) {
        cout << "Node" << getVertex(i) << " ";
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            cout << "   Node" << getVertex(v->getId()) << '[' << v->getWeight() << ']';
        }
        cout << endl;
    }
}

bool Graph::isLinked(int vtx1, int vtx2) {
    for (Node *v = mat[vtx1]; v != NULL; v = v->getLink()) {
        if (v->getId() == vtx2) return true;
    }
    return false;
}

void Graph::DFS(int vtx) {
    cout << "DFS" << endl;
    cout << "Number of Node : " << size << " Number of Edge : " << edgeCount << endl;
    
    adjSearch(vtx);

    cout << endl;
}

void Graph::adjSearch(int vtx) {
    visited[vtx] = true;
    cout << "Node" << getVertex(vtx) << " ";

    for (Node *v = mat[vtx]; v != NULL; v = v->getLink()) {
        if (visited[v->getId()] == false) adjSearch(v->getId());
    }
}

void Graph::BFS(int vtx) {
    visited[vtx] = true;
    cout << "BFS" << endl;
    cout << "Number of Node : " << size << " Number of Edge : " << edgeCount << endl;  
    cout << "Node" << getVertex(vtx) << " ";

    queue<int> queue;
    queue.push(vtx);

    while (!queue.empty()) {
        int vertice = queue.front();
        queue.pop();
        for (Node *v = mat[vertice]; v != NULL; v = v->getLink()) {
            int id = v->getId();
            if (!visited[id]) {
                visited[id] = true;
                cout << "Node" << getVertex(id) << " ";
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

void Graph::kruskal(int vtx) {
    cout << "Kruskal Algorithm" << endl;
    cout << "Number of Node : " << size << " Number of Edge : " << edgeCount << endl;

    int component = label[getVertex(vtx)];
    int count = 0;

    priority_queue<Path, vector<Path>, compare> nodeQueue;
    for (int i = 0; i < size; i++) {
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            if (label[v->getId()] == component || label[i] == component) {
                nodeQueue.push(Path(v->getWeight(), i, v->getId()));
            }
        }
        if (label[i] == component) {
            count++;
        }
    }

    VertexSets set(size);
    int edgeAccepted = 0;
    while (edgeAccepted < count - 1) {
        Path node = nodeQueue.top();
        nodeQueue.pop();
        int set1 = set.findSet(node.getVtx1());
        int set2 = set.findSet(node.getVtx2());
        if (set1 != set2) {
            cout << "Add Path : " << getVertex(node.getVtx1()) << " - " << getVertex(node.getVtx2()) << " cost : " << node.getKey() << endl;
            set.unionSets(set1, set2);
            edgeAccepted++;
        }
    }
}

void Graph::prim(int vtx) {
    cout << "Prim Algorithm" << endl;
    cout << "Number of Node : " << size << " Number of Edge : " << edgeCount << endl;

    bool selected[MAX_VTXS];
    int prev = vtx;
    int next;
    for (int i = 0; i < size; i++) selected[i] = false;
    selected[vtx] = true;

    int component = label[getVertex(vtx)];
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (label[i] == component) {
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        int minDist = 9999;
        for (Node *v = mat[prev]; v != NULL; v = v->getLink()) {
            if (v->getWeight() < minDist && !selected[v->getId()]) {
                minDist = v->getWeight();
                next = v->getId();
            }
        }
        cout << "Add Path : " << prev << " - " << next << " cost : " << minDist << endl;
        prev = next;
    }
}

void Graph::labelDFS(int vtx, int color) {
    visited[vtx] = true;
    label[vtx] = color;
    for (int i = 0; i < size; i++) {
        if (isLinked(vtx, i) && !visited[i]) {
            labelDFS(i, color);
        }
    }
}

void Graph::findConnectedComponent() {
    int count = 0;
    int lastIdx = 0;

    for (int i = 0; i < size; i++) {
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            if (!visited[v->getId()]) labelDFS(v->getId(), ++count);
        }
    }
    for (int i = 1; i < count + 1; i++) {
        cout << "\nComponent " << i << " : ";
        for (int j = 0; j < size; j++) {
            if (i == label[j]) {
                cout << j << " ";
            }
        }
    }
    cout << endl << "Number of Connected Component : " << count << endl;
}

void Graph::makeRandomGraph(int vtx, int edge) {
    int randWeight, randVtx1, randVtx2;

    for (int i = 0; i < vtx; i++) {
        insertVertex(i);
    }
    while (edgeCount < edge) {
        randVtx1 = rand() % vtx;
        randVtx2 = rand() % vtx;
        randWeight = rand() % 10 + 1;
        if (randVtx1 != randVtx2) {
            if (edgeCount == 0) insertEdge(randVtx1, randVtx2, randWeight);
            
            for (int i = 0; i < edgeCount; i++) {
                if (prev[i] != randVtx2 && next[i] != randVtx1) {
                    insertEdge(randVtx1, randVtx2, randWeight);
                    break;
                }
            }
        }
    }
}