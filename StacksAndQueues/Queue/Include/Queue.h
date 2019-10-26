#ifndef __QUEUE_H__
#define __QUEUE_H__

template<class T>
class Node {
    private:
        T data;
        Node<T>* next;
    public:
        Node(T data) {

            this->data = data;
            this->next = NULL;

        }

        ~Node() {

            this->next = NULL;

        }

        T getData() {

            return this->data;
        }
};

template<class T>
class Queue {
    private:
        T* front;
    public:
        Queue() {

            this->front = NULL;

        }

        ~Queue() {

            this->front = NULL;

        }
};

#endif