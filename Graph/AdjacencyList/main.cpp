#include "graph.h"

int main() {
    Graph graph;

    for (int i = 0; i < 4; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 2);
    graph.insertEdge(0, 3, 3);
    graph.insertEdge(1, 2, 4);
    graph.insertEdge(1, 3, 2);
    graph.insertEdge(2, 3, 1);
    cout << "Adjacency list graph\n";
    graph.printGraph();
    cout << "DFS ==> ";
    graph.resetVisited();
    graph.DFS(0);
    cout << "\nBFS ==> ";
    graph.resetVisited();
    graph.BFS(0);
    graph.kruskal();
    graph.prim(0);

    return 0;
}