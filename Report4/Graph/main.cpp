#include "graph.h"

int main() {
    Graph graph;

    graph.makeRandomGraph(30, 20);
/*
    for (int i = 0; i < 4; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 2);
    graph.insertEdge(0, 3, 3);
    graph.insertEdge(1, 2, 4);
    graph.insertEdge(1, 3, 2);
    graph.insertEdge(2, 3, 1);
*/
    graph.printGraph();
    cout << endl;
    graph.resetVisited();
    graph.DFS(1);
    cout << endl;
    graph.resetVisited();
    graph.BFS(1);
    graph.resetVisited();
    graph.findConnectedComponent();
    cout << endl;
    graph.kruskal(1);
    cout << endl;
    graph.prim(1);

    return 0;
}