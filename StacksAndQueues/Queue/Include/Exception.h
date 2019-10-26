#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

class empty_queue_exception : public std::exception {
    private:
        std::string msg;
    public:
        empty_queue_exception();
        ~empty_queue_exception();
        const char* what() const throw();
};

class null_peek_exception : public std::exception {
    private:
        std::string msg;
    public:
        null_peek_exception();
        ~null_peek_exception();
        const char* what() const throw();
};

#endif