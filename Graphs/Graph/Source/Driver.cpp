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
    graph.insertEdge(18, 100);
    graph.insertEdge(100, 2);
    graph.insertEdge(2, 5);

    graph.insertVertex(50);
    graph.insertEdge(2, 50);

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

    graph.print();

    vector<array<int, 2>> conn = graph.lookupVertex(50);

    cout << "Lookup 50: [";
    for(array<int, 2> tuple : conn)
        cout << "\t" << tuple.front();
    cout << "\t]" << endl << endl;

    cout << "2 --> 50 : " << graph.getWeight(2, 50) << endl << endl;

    graph.insertVertex(3);
    graph.insertEdge(2, 3);
    graph.insertVertex(6);
    graph.insertEdge(3, 6);
    graph.insertVertex(8);
    graph.insertEdge(6, 8);
    graph.insertEdge(8, 121);

    graph.deleteEdge(121, 8);
    graph.deleteVertex(6);
    graph.deleteVertex(8);
    graph.deleteVertex(3);

    graph.print();

    return 0;
}