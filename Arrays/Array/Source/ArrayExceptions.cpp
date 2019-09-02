#include "ArrayExceptions.h"

using namespace std;

/**
 * @brief Constructor that assembles and sets the error message to be shown if the ArrayIndexOutOfBounds 
 * exception is thrown.
 * 
 * @param index the index position that does not exist in the Array
 **/
ArrayIndexOutOfBounds::ArrayIndexOutOfBounds(int index) {

    stringstream sstr;
    sstr << "The value at index " << index << " does not exist.";

    this->msg = sstr.str();

}

const char* ArrayIndexOutOfBounds::what() const throw() {

    return this->msg.c_str();
}

/**
 * @brief Constructor that assembles and sets the error message to be shown if the ArrayUnderflow exception is thrown.
 **/
ArrayUnderflow::ArrayUnderflow() {

    this->msg = "Unable to pop. Array is empty.";

}

const char* ArrayUnderflow::what() const throw() {

    return this->msg.c_str();
}