#ifndef ARRAY_EXCEPTIONS_H
#define ARRAY_EXCEPTIONS_H

#include<exception>
#include<sstream>

/**
 * @brief An exception that is thrown when an Array is being accessed at an index that does not yet exist.
 * The purpose of this exception is to prevent memory that is outside the boundaries of the Array from
 * being referenced.
 **/
class ArrayIndexOutOfBounds : public std::exception {
    private:
        std::string msg;

    public:
        ArrayIndexOutOfBounds(int);

        const char* what() const throw();
};

/** 
 * @brief An exception that is thrown when a pop operation is attempted on a dynamic Array that is empty.
 * The purpose of this exception is to prevent memory that is outside the boundaries of the Array from
 * being referenced.
 **/
class ArrayUnderflow : public std::exception {
    private:
        std::string msg;

    public:
        ArrayUnderflow();

        const char* what() const throw();
};

#endif