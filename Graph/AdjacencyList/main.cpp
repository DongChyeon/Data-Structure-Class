#include "graph.h"

int main() {
    Graph graph;

    // Connected graph only can use prim, kruskal algorithm
    for (int i = 0; i < 8; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 6);
    graph.insertEdge(0, 2, 10);
    graph.insertEdge(2, 3, 7);
    graph.insertEdge(3, 4, 3);
    graph.insertEdge(1, 5, 2);
    graph.insertEdge(0, 5, 3);
    graph.insertEdge(0, 6, 6);
    graph.insertEdge(5, 6, 1);
    graph.insertEdge(2, 6, 1);
    graph.insertEdge(3, 6, 5);
    graph.insertEdge(3, 7, 4);
    graph.insertEdge(6, 7, 9);
    graph.insertEdge(4, 7, 4);

    // Find connected Component first.
    graph.findConnectedComponent();
    cout << endl;
    graph.kruskal(3);
    cout << endl;
    graph.prim(3);

    return 0;
}