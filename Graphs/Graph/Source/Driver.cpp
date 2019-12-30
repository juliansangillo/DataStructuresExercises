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

    graph.insertEdge(5, 0, true, 5);
    graph.insertEdge(5, 18, true, 15);
    graph.insertEdge(18, 100, true, 23);
    graph.insertEdge(100, 2, true, 8);
    graph.insertEdge(2, 5, true, 10);

    graph.insertVertex(50);
    graph.insertEdge(2, 50, false, 30);

    graph.insertVertex(1);
    graph.insertEdge(50, 1, false, 10);

    graph.insertVertex(121);
    graph.insertEdge(50, 121, true, 5);

    graph.insertVertex(69);
    graph.insertEdge(1, 69, false, 3);
    graph.insertEdge(69, 50, false, 5);
    graph.insertEdge(121, 69, true, 10);

    graph.insertVertex(999);
    graph.insertEdge(69, 999, true, 5);
    graph.insertEdge(121, 999, true, 10);
    graph.insertEdge(100, 999, true, 50);

    graph.print();

    vector<int> path1 = graph.lookupShortestPath(0, 999);

    cout << "Shortest Path: [";
    for(int v : path1)
        cout << "\t" << v;
    cout << "\t]" << endl;

    vector<int> path2 = graph.lookupCheapestPath(0, 999);

    cout << "Cheapest Path: [";
    for(int v : path2)
        cout << "\t" << v;
    cout << "\t]" << endl;

    return 0;
}