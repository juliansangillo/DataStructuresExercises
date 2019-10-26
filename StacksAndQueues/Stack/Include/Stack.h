#ifndef __STACK_H__
#define __STACK_H__

template<class T>
class Stack {
    private:
        T* stack;
        T* top;

        int buffer;
    public:
        Stack() {

            buffer = 5;

            stack = new T[buffer];
            top = stack[0];

        }

        ~Stack() {

            delete[] stack;
            stack = NULL;
            top = NULL;

        }
};

#endif