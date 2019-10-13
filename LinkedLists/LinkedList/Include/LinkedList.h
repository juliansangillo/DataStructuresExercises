#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template<class T>
class Node {
    private:
        T value;
    public:
        Node<T>* next;

        Node(T value) {

            this->value = value;
            this->next = NULL;

        }

        ~Node() {

            this->next = NULL;

        }

        T getVal() {

            return this->value;
        }

        void setVal(T value) {

            this->value = value;

        }
};

template<class T>
class LinkedList {
    public:
        Node<T>* head;
        Node<T>* tail;

        LinkedList(T value) {

            head = new Node<T>(value);
            tail = head;

        }

        ~LinkedList() {

            while(head != NULL) {
                Node<T>* node = head;
                head = head->next;

                delete node;
                node = NULL;
            }

            tail = NULL;
        }

        void prepend(T value) {

            Node<T>* node = new Node<T>(value);

            node->next = head;
            head = node;

        }

        void append(T value) {

            Node<T>* node = new Node<T>(value);

            tail->next = node;
            tail = node;

        }
};

#endif