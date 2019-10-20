#include "index_out_of_bounds.h"

#include <sstream>

index_out_of_bounds::index_out_of_bounds() {

    msg = "Index does not exist in linked list. Please try again!";

}

const char* index_out_of_bounds::what() const throw() {

    return msg.c_str();
}