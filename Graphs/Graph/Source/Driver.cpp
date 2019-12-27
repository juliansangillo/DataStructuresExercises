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
    graph.insertEdge(2, 50, true, 15);

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

    graph.setWeight(5, 2, 8);
    cout << "5 --> 2 : " << graph.getWeight(5, 2) << endl << endl;

    graph.removeWeight(2, 50);
    graph.removeWeight(5, 2);

    graph.print();

    return 0;
}