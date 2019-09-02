#include "TableExceptions.h"

using namespace std;

/**
 * @brief A constructor that assembles the error message to be displayed if an 
 * ElementDoesNotExist exception is thrown.
 * 
 * @param key the key that was accessed but does not exist
 **/
ElementDoesNotExist::ElementDoesNotExist(string key) {

    stringstream sstr;
    sstr << "Element with key '" << key << "' does not exist in hash table.";

    this->msg = sstr.str();

}

const char* ElementDoesNotExist::what() const throw() {

    return this->msg.c_str();
}

/**
 * @brief A constructor that assembles the error message to be displayed if a 
 * DuplicateKey exception is thrown.
 * 
 * @param key the key that already exists
 **/
DuplicateKey::DuplicateKey(string key) {

    stringstream sstr;
    sstr << "The key '" << key << "' already exists in hash table.";

    this->msg = sstr.str();

}

const char* DuplicateKey::what() const throw() {

    return this->msg.c_str();
}