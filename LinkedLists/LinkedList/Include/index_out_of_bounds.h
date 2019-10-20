#ifndef _INDEX_OUT_OF_BOUNDS_H
#define _INDEX_OUT_OF_BOUNDS_H

#include <string>

class index_out_of_bounds : public std::exception {
    private:
        std::string msg;
    public:
        index_out_of_bounds(int index);
        virtual const char* what() const throw();
};

#endif