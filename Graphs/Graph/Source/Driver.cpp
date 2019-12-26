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
    graph.print();

    return 0;
}