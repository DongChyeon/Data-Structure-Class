#include "graph.h"

int main() {
    Graph graph;

    // Connected graph only can use prim, kruskal algorithm
    for (int i = 0; i < 9; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 10);
    graph.insertEdge(1, 2, 10);
    graph.insertEdge(2, 3, 10);
    graph.insertEdge(3, 7 ,10);
    graph.insertEdge(6, 3, 10);
    graph.insertEdge(4, 2, 10);
    graph.insertEdge(5, 6, 10);
    graph.insertEdge(0, 5, 10);
    graph.insertEdge(0, 8, 10);

    graph.printGraph();
    cout << endl;
    graph.spanningTreeByBFS(7);
    /*
    graph.findConnectedComponent();
    cout << endl;
    graph.kruskal(0);
    cout << endl;
    graph.prim(0);
    */

    return 0;
}