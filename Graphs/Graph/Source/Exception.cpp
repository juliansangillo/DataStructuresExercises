#include "Exception.h"

invalid_weight::invalid_weight(int weight) {

    std::stringstream stream;
    stream << "\'" << weight << "\' is an invalid weight value. Weights of edges must be integers greater than zero";

    this->msg = stream.str();

}

const char* invalid_weight::what() const throw() {

    return this->msg.c_str();
}