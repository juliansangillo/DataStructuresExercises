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

    graph.insertEdge(5, 0);
    graph.insertEdge(5, 18);
    //graph.insertEdge(18, 5, false);
    graph.insertEdge(18, 100);
    graph.insertEdge(100, 2);
    graph.insertEdge(2, 5);

    graph.insertVertex(50);
    graph.insertEdge(2, 50);
    //graph.insertEdge(50, 2, false);

    graph.insertVertex(1);
    graph.insertEdge(50, 1);

    graph.insertVertex(121);
    graph.insertEdge(50, 121);

    graph.insertVertex(69);
    graph.insertEdge(1, 69);
    graph.insertEdge(50, 69);
    graph.insertEdge(121, 69);

    graph.insertVertex(999);
    graph.insertEdge(69, 999);
    graph.insertEdge(121, 999);
    graph.insertEdge(100, 999);
    //graph.insertEdge(100, 999, false);
    //graph.insertEdge(999, 100, false);

    graph.print();

    vector<int> path = graph.lookupShortestPath(100, 1);

    cout << "[";
    for(int v : path)
        cout << "\t" << v;
    cout << "\t]" << endl;

    return 0;
}