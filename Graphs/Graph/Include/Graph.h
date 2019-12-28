#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<utility>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>

#include "Exception.h"

template<class T>
class Graph {
    private:
        std::unordered_map<T, int> vertexMap;
        std::unordered_map<T, std::unordered_map<T, int>> matrix;

        bool search(T target, std::queue<std::pair<T, T>> vertex, std::unordered_map<T, T> &predecessor) {

            using namespace std;

            pair<T, T> vertPair;
            T current;

            while(!vertex.empty()) {
                vertPair = vertex.front();
                vertex.pop();

                current = vertPair.first;

                if(predecessor.find(current) != predecessor.end())
                    continue;

                predecessor.insert(vertPair);
                
                if(current == target)
                    return true;

                vector<array<T, 2>> next = this->lookupVertex(current);
                for(array<T, 2> n : next)
                    vertex.push(make_pair(n[0], current));
            }

            return false;
        }

        std::vector<T> traceback(T src, T dest, std::unordered_map<T, T> predecessor) {
            
            std::vector<T> path;
            std::list<T> trace;

            T current = dest;
            T prev = predecessor.find(dest)->second;

            while(current != src) {
                trace.push_front(current);

                current = prev;
                prev = predecessor.find(current)->second;
            }
            trace.push_front(src);

            while(!trace.empty()) {
                path.push_back(trace.front());

                trace.pop_front();
            }

            return path;
        }
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

        void insertEdge(T vertX, T vertY, bool bidirectional = true, int weight = 1) {

            if(matrix.find(vertX) == matrix.end())
                throw vertex_doesnt_exist<T>(vertX);

            if(matrix[vertX].find(vertY) == matrix[vertX].end())
                throw vertex_doesnt_exist<T>(vertY);

            if(matrix[vertX][vertY] >= 1)
                throw edge_already_exists<T>(vertX, vertY);

            if(bidirectional) {
                if(matrix[vertY][vertX] >= 1)
                    throw edge_already_exists<T>(vertY, vertX);

                matrix[vertX][vertY] = weight;
                matrix[vertY][vertX] = weight;
            }
            else
                matrix[vertX][vertY] = weight;

        }

        void deleteVertex(T vert) {

            if(matrix.find(vert) == matrix.end())
                throw vertex_doesnt_exist<T>(vert);

            using namespace std;

            matrix.erase(vert);
            vertexMap.erase(vert);

            typename unordered_map<T, unordered_map<T, int>>::iterator x;
            for(x = matrix.begin(); x != matrix.end(); x++)
                (x->second).erase(vert);

        }

        void deleteEdge(T vertX, T vertY, bool bothDirections = true) {

            if(matrix.find(vertX) == matrix.end())
                throw vertex_doesnt_exist<T>(vertX);

            if(matrix[vertX].find(vertY) == matrix[vertX].end())
                throw vertex_doesnt_exist<T>(vertY);

            if(matrix[vertX][vertY] == 0)
                throw edge_doesnt_exist<T>(vertX, vertY);

            if(bothDirections) {
                if(matrix[vertY][vertX] == 0)
                    throw edge_doesnt_exist<T>(vertY, vertX);

                matrix[vertX][vertY] = 0;
                matrix[vertY][vertX] = 0;
            }
            else
                matrix[vertX][vertY] = 0;

        }

        std::vector<std::array<T, 2>> lookupVertex(T vert) {

            if(matrix.find(vert) == matrix.end())
                throw vertex_doesnt_exist<T>(vert);

            std::vector<std::array<T, 2>> connections;
            std::unordered_map<T, int> map = matrix[vert];

            typename std::unordered_map<T, int>::iterator y;
            for(y = map.begin(); y != map.end(); y++)
                if(y->second >= 1)
                    connections.push_back(std::array<T, 2> {y->first, y->second});
                    
            return connections;
        }

        std::vector<T> lookupShortestPath(T src, T dest) {

            if(matrix.find(src) == matrix.end())
                throw vertex_doesnt_exist<T>(src);

            if(matrix.find(dest) == matrix.end())
                throw vertex_doesnt_exist<T>(dest);

            using namespace std;

            queue<pair<T, T>> vertex;
            unordered_map<T, T> predecessor;
            vector<T> path;

            vertex.push(make_pair(src, src));

            bool found = this->search(dest, vertex, predecessor);

            if(found)
                path = this->traceback(src, dest, predecessor);

            return path;
        }

        void setWeight(T vertX, T vertY, int weight, bool bothDirections = true) {

            if(matrix.find(vertX) == matrix.end())
                throw vertex_doesnt_exist<T>(vertX);

            if(matrix[vertX].find(vertY) == matrix[vertX].end())
                throw vertex_doesnt_exist<T>(vertY);

            if(matrix[vertX][vertY] == 0)
                throw edge_doesnt_exist<T>(vertX, vertY);

            if(weight < 0)
                throw invalid_weight<T>(weight);

            if(bothDirections) {

                if(matrix[vertY][vertX] == 0)
                    throw edge_doesnt_exist<T>(vertY, vertX);

                matrix[vertX][vertY] = weight;
                matrix[vertY][vertX] = weight;

            }
            else
                matrix[vertX][vertY] = weight;
            
        }

        void removeWeight(T vertX, T vertY, bool bothDirections = true) {

            if(matrix.find(vertX) == matrix.end())
                throw vertex_doesnt_exist<T>(vertX);

            if(matrix[vertX].find(vertY) == matrix[vertX].end())
                throw vertex_doesnt_exist<T>(vertY);

            if(matrix[vertX][vertY] == 0)
                throw edge_doesnt_exist<T>(vertX, vertY);

            if(bothDirections) {

                if(matrix[vertY][vertX] == 0)
                    throw edge_doesnt_exist<T>(vertY, vertX);

                matrix[vertX][vertY] = 1;
                matrix[vertY][vertX] = 1;

            }
            else
                matrix[vertX][vertY] = 1;
            
        }

        int getWeight(T vertX, T vertY) {

            if(matrix.find(vertX) == matrix.end())
                throw vertex_doesnt_exist<T>(vertX);

            if(matrix[vertX].find(vertY) == matrix[vertX].end())
                throw vertex_doesnt_exist<T>(vertY);

            if(matrix[vertX][vertY] == 0)
                throw edge_doesnt_exist<T>(vertX, vertY);

            return matrix[vertX][vertY];
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