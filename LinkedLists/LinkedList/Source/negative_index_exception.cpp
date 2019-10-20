#include "negative_index_exception.h"

negative_index_exception::negative_index_exception() {

    msg = "Index cannot be negative!";

}

const char* negative_index_exception::what() const throw() {

    return msg.c_str();
}