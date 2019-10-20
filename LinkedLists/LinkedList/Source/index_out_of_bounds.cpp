#include "index_out_of_bounds.h"

#include <sstream>

index_out_of_bounds::index_out_of_bounds(int index) {

    std::stringstream stream;
    stream << "Index entered [" << index << "]. Index does not exist in linked list. Please try again!";

    msg = stream.str();

}

const char* index_out_of_bounds::what() const throw() {

    return msg.c_str();
}