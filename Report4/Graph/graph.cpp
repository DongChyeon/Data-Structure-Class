#include "graph.h"
#include <vector>

Graph::Graph() {
    size = 0;
    edgeSize = 0;
    vtxCount = 0;
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
    edgeSize = 0;
    vtxCount = 0;
}

bool Graph::isEmpty() { return size == 0; }
bool Graph::isFull() { return size >= MAX_VTXS; }

int Graph::getVertex(int id) { return vertices[id]; }
int Graph::getEdge(int vtx1, int vtx2) {
    for (Node *v = mat[vtx1]; v != NULL; v = v->getLink()) {
        if (v->getId() == vtx2) return v->getWeight();
    }
    return -1;
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
    mat[vtx2] = new Node(vtx1, mat[vtx2], weight);
    path[edgeSize] = Path(weight, vtx1, vtx2);

    edgeSize++;
}

void Graph::printGraph() {
    for (int i = 0; i < size; i++) {
        cout << "Node" << getVertex(i) << " ";
        for (Node *v = mat[i]; v != NULL; v = v->getLink()) {
            cout << "   Node" << getVertex(v->getId()) << '[' << v->getWeight() << ']';
        }
        cout << endl;
    }
    cout << "Number of Nodes : " << size << " Number of Edges : " << edgeSize << endl;
}

bool Graph::isLinked(int vtx1, int vtx2) {
    for (Node *v = mat[vtx1]; v != NULL; v = v->getLink()) {
        if (v->getId() == vtx2) return true;
    }
    return false;
}

void Graph::DFS(int vtx) {
    cout << "DFS" << endl;
    vtxCount = 0;

    adjSearch(vtx);

    cout << endl;
    cout << "Number of Nodes : " << vtxCount << " Number of Edges : " << vtxCount - 1 << endl;
}

void Graph::adjSearch(int vtx) {
    visited[vtx] = true;
    cout << "Node" << getVertex(vtx) << " ";

    for (Node *v = mat[vtx]; v != NULL; v = v->getLink()) {
        if (visited[v->getId()] == false) adjSearch(v->getId());
    }
    vtxCount++;
}

void Graph::BFS(int vtx) {
    resetVisited();
    vtxCount = 1;
    visited[vtx] = true;
    cout << "BFS" << endl;  
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
                vtxCount++;
            }
        }
    }
    cout << endl;
    cout << "Number of Nodes : " << vtxCount << " Number of Edges : " << vtxCount - 1 << endl;
}

void Graph::resetVisited() {
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
}

void Graph::kruskal(int vtx) {   
    cout << "Kruskal Algorithm" << endl;

    int component = label[getVertex(vtx)];
    vtxCount = 0;

    for (int i = 0; i < size; i++) {
        if (label[i] == component) vtxCount++;
    }

    priority_queue<Path, vector<Path>, compare> nodeQueue;
    for (int i = 0; i < edgeSize; i++) {
        Path node = path[i];
        if (label[node.getVtx1()] == component && label[node.getVtx2()] == component) {
            nodeQueue.push(node);
        }
    }   

    VertexSets set(size);
    vector<Path> routes;
    
    int edgeAccepted = 0;
    while (edgeAccepted < vtxCount - 1) {
        Path node = nodeQueue.top();
        nodeQueue.pop();
        int set1 = set.findSet(node.getVtx1());
        int set2 = set.findSet(node.getVtx2());
        if (set1 != set2) {
            cout << "Choose Path : " << getVertex(node.getVtx1()) << " - " << 
                    getVertex(node.getVtx2()) << " cost : " << node.getWeight() << endl;
            set.unionSets(set1, set2);
            edgeAccepted++;
            routes.push_back(node);
        }
    }

    // Print shortest path
    vector<Path>::iterator iter = routes.begin();

    int next = iter->getVtx2();
    if (startCheck(next, routes)) {
        cout << "Node" << iter->getVtx1() << " ";
    } else {
        next = iter->getVtx1();
        cout << "Node" << iter->getVtx2() << " ";
    }
    routes.erase(iter);

    while (routes.size() > 0) {
        for (iter = routes.begin(); iter != routes.end(); iter++) {
            if (iter->getVtx1() == next) {
                cout << "Node" << iter->getVtx1() << " ";
                if (routes.size() == 1) cout << "Node" << iter->getVtx2();
                next = iter->getVtx2();
                routes.erase(iter);
                break;
            }
            if (iter->getVtx2() == next) {
                cout << "Node" << iter->getVtx2() << " "; 
                if (routes.size() == 1) cout << "Node" << iter->getVtx1();
                next = iter->getVtx1();
                routes.erase(iter);
                break;
            }
        }
    }
    cout << endl;
    cout << "Number of Nodes : " << vtxCount << " Number of Edges : " << vtxCount - 1 << endl;
}

void Graph::prim(int vtx) {
    cout << "Prim Algorithm" << endl;

    bool selected[MAX_VTXS];
    int prev = vtx;
    int next;
    for (int i = 0; i < size; i++) selected[i] = false;
    selected[vtx] = true;

    int component = label[getVertex(vtx)];
    vtxCount = 0;

    for (int i = 0; i < size; i++) {
        if (label[i] == component) {
            vtxCount++;
        }
    }

    vector<int> routes;
    for (int i = 0; i < vtxCount - 1; i++) {
        int minDist = 9999;

        for (Node *v = mat[prev]; v != NULL; v = v->getLink()) {
            if (v->getWeight() < minDist && !selected[v->getId()]) {
                minDist = v->getWeight();
                next = v->getId();
            }
        }

        if (minDist == 9999) {
            cout << "Error : Cannot find path" << endl;
            return;
        }

        selected[next] = true;
        cout << "Choose Path : " << prev << " - " << next << " cost : " << minDist << endl;
        if (i == 0) routes.push_back(prev);
        routes.push_back(next);
        prev = next;
    }

    for (vector<int>::iterator iter = routes.begin(); iter != routes.end(); iter++) {
        cout << "Node" << *iter << " ";
    }
    cout << endl;
    cout << "Number of Nodes : " << vtxCount << " Number of Edges : " << vtxCount - 1 << endl;
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
    resetVisited();
    int count = 0;

    for (int i = 0; i < size; i++) label[i] = 0;
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

    int current_size = size;
    int current_edgeSize = edgeSize;
    for (int i = current_size; i < current_size + vtx; i++) {
        insertVertex(i);
    }
    while (edgeSize < current_edgeSize + edge) {
        do {
            randVtx1 = rand() % (size - current_size) + current_size;
            randVtx2 = rand() % (size - current_size) + current_size;
        } while (randVtx1 == randVtx2);
        randWeight = rand() % 30 + 1;

        if (edgeSize == 0) {
            insertEdge(randVtx1, randVtx2, randWeight);
        } else {
            if (!isDupNode(randVtx1, randVtx2))
                insertEdge(randVtx1, randVtx2, randWeight);
        }
    }
}

bool Graph::isDupNode(int vtx1, int vtx2) {
    for (int i = 0; i < edgeSize; i++) {
        if (vtx1 == path[i].getVtx1() && vtx2 == path[i].getVtx2())
            return true;
    }
    for (int i = 0; i < edgeSize; i++) {
        if (vtx1 == path[i].getVtx2() && vtx2 == path[i].getVtx1())
            return true;
    }

    return false;
}

bool Graph::startCheck(int next, vector<Path> routes) {
    for (vector<Path>::iterator iter = routes.begin(); iter != routes.end(); iter++) {
        if (iter->getVtx1() == next) {
            //cout << "Node" << iter->getVtx2();
            return true;
        }
    }

    return false;
}