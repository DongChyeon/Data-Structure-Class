#include "graph.h"

int main() {
    Graph graph;

/* 2 Connected Components;
    for (int i = 0; i < 6; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 2);
    graph.insertEdge(0, 3, 3);
    graph.insertEdge(1, 2, 4);
    graph.insertEdge(1, 3, 2);
    graph.insertEdge(2, 3, 1);
    graph.insertEdge(4, 5, 2);
*/

    for (int i = 0; i < 4; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 2);
    graph.insertEdge(0, 3, 3);
    graph.insertEdge(1, 2, 4);
    graph.insertEdge(1, 3, 2);
    graph.insertEdge(2, 3, 1);

    graph.printGraph();
    cout << endl;
    graph.resetVisited();
    graph.DFS(0);
    cout << endl;
    graph.resetVisited();
    graph.BFS(0);
    graph.resetVisited();
    graph.findConnectedComponent();
    cout << endl;
    graph.kruskal();
    cout << endl;
    graph.prim(0);

    return 0;
}