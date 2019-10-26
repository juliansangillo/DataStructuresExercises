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

            if(this->next != NULL)
                delete this->next;
            this->next = NULL;

        }

        void setNext(Node<T>* next) {

            this->next = next;

        }

        T getData() {

            return this->data;
        }
};

template<class T>
class Queue {
    private:
        Node<T>* front;
        Node<T>* back;
    public:
        Queue() {

            this->front = NULL;
            this->back = NULL;

        }

        ~Queue() {

            delete this->front;
            this->front = NULL;
            this->back = NULL;

        }

        bool isEmpty() {

            if(this->front == NULL)
                return true;
            else
                return false;
        }

        void enqueue(T data) {

            Node<T>* node = new Node<T>(data);

            if(isEmpty()) {
                this->front = node;
                this->back = this->front;
                std::cout << "Enqueued: " << this->back->getData() << std::endl;
                return;
            }

            this->back->setNext(node);
            this->back = node;
            std::cout << "Enqueued: " << this->back->getData() << std::endl;

        }
};

#endif