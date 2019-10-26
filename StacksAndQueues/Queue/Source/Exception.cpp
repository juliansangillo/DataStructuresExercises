#include "Exception.h"

empty_queue_exception::empty_queue_exception() {

    msg = "Queue is empty. Unable to dequeue more data.";

}
empty_queue_exception::~empty_queue_exception() {}

const char* empty_queue_exception::what() const throw() {

    return msg.c_str();
}

null_peek_exception::null_peek_exception() {

    msg = "Cannot peek when queue is empty.";

}
null_peek_exception::~null_peek_exception() {}

const char* null_peek_exception::what() const throw() {

    return msg.c_str();
}