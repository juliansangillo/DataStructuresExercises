#include "Exception.h"

stack_overflow_exception::stack_overflow_exception() {

    msg = "Stack is full. Unable to push more data.";

}
stack_overflow_exception::~stack_overflow_exception() {}

const char* stack_overflow_exception::what() const throw() {

    return msg.c_str();
}

stack_underflow_exception::stack_underflow_exception() {

    msg = "Stack is empty. Unable to pop more data.";

}
stack_underflow_exception::~stack_underflow_exception() {}

const char* stack_underflow_exception::what() const throw() {

    return msg.c_str();
}

null_peek_exception::null_peek_exception() {

    msg = "Cannot peek when stack is empty.";

}
null_peek_exception::~null_peek_exception() {}

const char* null_peek_exception::what() const throw() {

    return msg.c_str();
}