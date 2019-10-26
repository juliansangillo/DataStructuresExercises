#ifndef __STACK_H__
#define __STACK_H__

#include "Exception.h"

template<class T>
class Stack {
    private:
        T* stack;
        T* top;

        int buffer;
    public:
        Stack() {

            this->buffer = 5;

            this->stack = new T[this->buffer];
            this->top = NULL;

        }

        ~Stack() {

            delete[] this->stack;
            this->stack = NULL;
            this->top = NULL;

        }

        bool isEmpty() {

            if(this->top == NULL)
                return true;
            else
                return false;
        }

        void push(T data) {

            if(isEmpty()) {
                this->top = this->stack;
            }
            else {
                this->top++;
            }

            if(top >= stack + buffer)
                throw stack_overflow_exception();

            *this->top = data;

        }

        T pop() {

            if(isEmpty())
                throw stack_underflow_exception();

            T data = *this->top;
            this->top--;

            if(this->top < this-> stack)
                this->top = NULL;

            return data;
        }

        T peek() {

            if(isEmpty())
                throw null_peek_exception();

            return *this->top;
        }
};

#endif