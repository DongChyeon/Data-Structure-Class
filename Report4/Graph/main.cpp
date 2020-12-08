#include "graph.h"

int main() {
    Graph graph;

    // Connected graph only can use prim, kruskal algorithm
    for (int i = 0; i < 7; i++) {
        graph.insertVertex(i);
    }
    graph.insertEdge(0, 1, 28);
    graph.insertEdge(1, 2, 16);
    graph.insertEdge(2, 3, 12);
    graph.insertEdge(3, 4, 22);
    graph.insertEdge(4, 5, 25);
    graph.insertEdge(5, 0, 10);
    graph.insertEdge(4, 6, 24);
    graph.insertEdge(6, 1, 14);
    graph.insertEdge(3, 6, 18);

    // Make random graph(Does not affect existing graphs)
    graph.makeRandomGraph(50, 30);

    graph.printGraph();
    cout << endl;
    graph.DFS(7);
    cout << endl;
    graph.BFS(7);
    cout << endl;
    graph.spanningTreeByBFS(7);
    graph.findConnectedComponent();
    cout << endl;
    graph.kruskal(0);
    cout << endl;
    graph.prim(0);

    return 0;
}