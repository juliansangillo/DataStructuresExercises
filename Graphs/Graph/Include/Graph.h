#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<unordered_map>

#include "Exception.h"

template<class T>
class Graph {
    private:
        std::unordered_map<T, int> vertexMap;
        std::unordered_map<T, std::unordered_map<T, int>> matrix;
    public:
        Graph() { }

        bool isEmpty() {

            if(matrix.empty())
                return true;
            return false;
        }

        void insertVertex(T data) {

            if(matrix.find(data) != matrix.end())
                throw vertex_already_exists<T>(data);

            using namespace std;

            typename unordered_map<T, unordered_map<T, int>>::iterator x;

            vertexMap.insert(make_pair(data, 0));

            for(x = matrix.begin(); x != matrix.end(); x++)
                (x->second).insert(make_pair(data, 0));

            matrix.insert(make_pair(data, vertexMap));

        }

        void insertEdge(T vert1, T vert2, bool bidirectional, int weight = 1) {

            if(matrix.find(vert1) == matrix.end())
                throw vertex_doesnt_exist<T>(vert1);

            if(matrix[vert1].find(vert2) == matrix[vert1].end())
                throw vertex_doesnt_exist<T>(vert2);

            if(matrix[vert1][vert2] >= 1)
                throw edge_already_exists<T>(vert1, vert2);

            if(bidirectional) {
                if(matrix[vert2][vert1] >= 1)
                    throw edge_already_exists<T>(vert2, vert1);

                matrix[vert1][vert2] = weight;
                matrix[vert2][vert1] = weight;
            }
            else
                matrix[vert1][vert2] = weight;

        }

        void print() {
            
            using namespace std;

            if(!isEmpty()) {
                typename unordered_map<T, unordered_map<T, int>>::iterator x;
                typename unordered_map<T, int>::iterator y;

                x = matrix.begin();
            
                for(y = (x->second).begin(); y != (x->second).end(); y++)
                    cout << "\t" << y->first;
                cout << endl << endl;

                for(x = matrix.begin(); x != matrix.end(); x++) {
                    cout << x->first;
                    
                    for(y = (x->second).begin(); y != (x->second).end(); y++)
                        cout << "\t" << y->second;
                    cout << endl << endl;
                }
            }
            else
                cout << "Null" << endl;

        }
};

#endif