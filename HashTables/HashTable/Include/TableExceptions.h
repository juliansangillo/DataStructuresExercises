#ifndef TABLE_EXCEPTIONS_H
#define TABLE_EXCEPTIONS_H

#include <exception>
#include <sstream>

/**
 * @brief An ElementDoesNotExist exception is thrown if a particular key is accessed but does not exist
 * in the HashTable.
 **/
class ElementDoesNotExist : public std::exception {
    private:
        std::string msg;

    public:
        ElementDoesNotExist(std::string);
        
        const char* what() const throw();
};

/**
 * @brief A DuplicateKey exception is thrown if a key-value pair is attempting to be added to the HashTable
 * but that exact key already exists.
 **/
class DuplicateKey : public std::exception {
    private:
        std::string msg;

    public:
        DuplicateKey(std::string);

        const char* what() const throw();
};

#endif