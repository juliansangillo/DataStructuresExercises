#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include<exception>
#include<sstream>

template<class T>
class vertex_already_exists : public std::exception {
    private:
        std::string msg;
    public:
        vertex_already_exists(T vertex) {

            std::stringstream stream;
            stream << "The vertex \'" << vertex << "\' already exists in this graph";

            msg = stream.str();

        }

        virtual const char* what() const throw() {

            return msg.c_str();
        }
};

template<class T>
class vertex_doesnt_exist : public std::exception {
    private:
        std::string msg;
    public:
        vertex_doesnt_exist(T vertex) {

            std::stringstream stream;
            stream << "The vertex \'" << vertex << "\' doesn't exist in this graph";

            msg = stream.str();

        }

        virtual const char* what() const throw() {

            return msg.c_str();
        }
};

template<class T>
class edge_already_exists : public std::exception {
    private:
        std::string msg;
    public:
        edge_already_exists(T vert1, T vert2) {

            std::stringstream stream;
            stream << "The edge \'" << vert1 << " --> " << vert2 << "\' already exists in this graph";

            msg = stream.str();

        }

        virtual const char* what() const throw() {

            return msg.c_str();
        }
};

template<class T>
class edge_doesnt_exist : public std::exception {
    private:
        std::string msg;
    public:
        edge_doesnt_exist(T vert1, T vert2) {

            std::stringstream stream;
            stream << "The edge \'" << vert1 << " --> " << vert2 << "\' doesn't exist in this graph";

            msg = stream.str();

        }

        virtual const char* what() const throw() {

            return msg.c_str();
        }
};

class invalid_weight : public std::exception {
    private:
        std::string msg;
    public:
        invalid_weight(int);
        virtual const char* what() const throw();
};

#endif