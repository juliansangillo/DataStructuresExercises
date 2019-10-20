#ifndef _NEGATIVE_INDEX_EXCEPTION_H
#define _NEGATIVE_INDEX_EXCEPTION_H

#include <string>

class negative_index_exception : public std::exception {
    private:
        std::string msg;
    public:
        negative_index_exception(int index);
        virtual const char* what() const throw();
};

#endif