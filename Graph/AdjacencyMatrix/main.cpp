#include "graph.h"

int main() {
    Graph graph;

    for (int i = 1; i < 5; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 3);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 3);
    cout << "Adjacency matrix graph\n";
    graph.display();
    cout << "DFS ==> ";
    graph.resetVisited();
    graph.DFS(0);
    cout << "\nBFS ==> ";
    graph.resetVisited();
    graph.BFS(0);

    return 0;
}