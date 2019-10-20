#include <sstream>

#include "negative_index_exception.h"

negative_index_exception::negative_index_exception(int index) {

    std::stringstream stream;
    stream << "Index entered [" << index << "]. Index cannot be negative!";

    msg = stream.str();

}

const char* negative_index_exception::what() const throw() {

    return msg.c_str();
}