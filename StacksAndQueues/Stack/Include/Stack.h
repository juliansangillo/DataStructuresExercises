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
            top = NULL;

        }

        ~Stack() {

            delete[] stack;
            stack = NULL;
            top = NULL;

        }

        void push(T data) {

            if(top == NULL) {
                top = stack;
            }
            else {
                top++;
            }

            *top = data;

        }

        void testPrint() {

            for(int i = 0; i < buffer; i++)
                std::cout << stack[i] << std::endl;
            std::cout << std::endl;

        }
};

#endif