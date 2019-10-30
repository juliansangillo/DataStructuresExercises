#include "Exception.h"

duplicate_value_exception::duplicate_value_exception() {

    this->msg = "Cannot insert duplicate values into Tree.";

}
duplicate_value_exception::~duplicate_value_exception() {}

const char* duplicate_value_exception::what() const throw() {

    return this->msg.c_str();
}

node_not_found_exception::node_not_found_exception() {

    this->msg = "Cannot remove node. Node was not found in Tree.";

}
node_not_found_exception::~node_not_found_exception() {}

const char* node_not_found_exception::what() const throw() {

    return this->msg.c_str();
}