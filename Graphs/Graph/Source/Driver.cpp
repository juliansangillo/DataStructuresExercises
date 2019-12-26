#include <iostream>

#include "Graph.h"

using namespace std;

int main() {

    Graph<int> graph;

    graph.insertVertex(18);
    graph.insertVertex(5);
    graph.insertVertex(0);
    graph.insertVertex(2);
    graph.insertVertex(100);

    graph.insertEdge(5, 0, true);
    graph.insertEdge(5, 18, true);
    graph.insertEdge(18, 100, true);
    graph.insertEdge(100, 2, true);
    graph.insertEdge(2, 5, true);

    graph.insertVertex(50);
    graph.insertEdge(2, 50, true);

    graph.insertVertex(1);
    graph.insertEdge(50, 1, true);

    graph.insertVertex(121);
    graph.insertEdge(50, 121, true);

    graph.insertVertex(69);
    graph.insertEdge(1, 69, true);
    graph.insertEdge(50, 69, true);
    graph.insertEdge(121, 69, true);

    graph.insertVertex(999);
    graph.insertEdge(69, 999, true);
    graph.insertEdge(121, 999, true);
    graph.insertEdge(100, 999, true);

    graph.print();

    return 0;
}