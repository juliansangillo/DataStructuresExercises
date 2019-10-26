#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

class stack_overflow_exception : public std::exception {
    private:
        std::string msg;
    public:
        stack_overflow_exception();
        ~stack_overflow_exception();
        const char* what() const throw();
};

class stack_underflow_exception : public std::exception {
    private:
        std::string msg;
    public:
        stack_underflow_exception();
        ~stack_underflow_exception();
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