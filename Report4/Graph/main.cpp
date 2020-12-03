#include "graph.h"

int main() {
    Graph graph;

    /* Connect graph only can use prim, kruskal algorithm
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
    graph.kruskal(0);
    cout << endl;
    graph.prim(0);
    */

    graph.makeRandomGraph(50, 30);
    graph.printGraph();
    cout << endl;
    graph.resetVisited();
    graph.DFS(0);
    cout << endl;
    graph.resetVisited();
    graph.BFS(0);
    graph.resetVisited();
    graph.findConnectedComponent();
    

    return 0;
}