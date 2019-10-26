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

        T pop() {

            T data = *top;
            top--;

            return data;
        }

        T peek() {

            return *top;
        }

        void testPrint() {

            if(top == NULL)
                return;

            for(int* i = stack; i <= top; i++)
                std::cout << *i << std::endl;
            std::cout << std::endl;

        }
};

#endif