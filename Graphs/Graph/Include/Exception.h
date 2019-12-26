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

#endif