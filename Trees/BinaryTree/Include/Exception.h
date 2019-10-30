#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

class duplicate_value_exception : public std::exception {
    private:
        std::string msg;
    public:
        duplicate_value_exception();
        ~duplicate_value_exception();
        const char* what() const throw();
};

class node_not_found_exception : public std::exception {
    private:
        std::string msg;
    public:
        node_not_found_exception();
        ~node_not_found_exception();
        const char* what() const throw();
};

#endif