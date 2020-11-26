#include "graph.h"

int main() {
    Graph graph;

    for (int i = 0; i < 4; i++) {
        graph.insertVertex('A' + i);
    }
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 3);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 3);
    printf("Adjacency matrix graph\n");
    graph.display();
}