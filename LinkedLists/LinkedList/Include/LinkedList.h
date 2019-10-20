#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "negative_index_exception.h"
#include "index_out_of_bounds.h"

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
    private:
        int length;

        Node<T>* traverse(int index) const throw() {

            if(index < 0)
                throw negative_index_exception();
            else if(index >= this->length)
                throw index_out_of_bounds();

            Node<T>* current = head;
            int counter = 0;
            while(counter != index) {
                current = current->next;
                counter++;
            }

            return current;
        }
    public:
        Node<T>* head;
        Node<T>* tail;

        LinkedList(T value) {

            head = new Node<T>(value);
            tail = head;

            this->length = 1;

        }

        ~LinkedList() {

            while(head != NULL) {
                Node<T>* node = head;
                head = head->next;

                delete node;
                node = NULL;

                this->length--;
            }

            tail = NULL;
        }

        void prepend(T value) {

            Node<T>* node = new Node<T>(value);

            node->next = head;
            head = node;

            this->length++;

        }

        void append(T value) {

            Node<T>* node = new Node<T>(value);

            tail->next = node;
            tail = node;

            this->length++;

        }

        void dropHead() {

            Node<T>* garbage = head;
            head = head->next;

            delete garbage;
            garbage = NULL;

            this->length--;

        }

        void dropTail() {

            Node<T>* garbage = tail;
            tail = this->traverse(this->length - 2);

            delete garbage;
            garbage = NULL;

            this->length--;

        }

        T find(int index) const throw() {

            return this->traverse(index)->getVal();
        }

        void insert(int index, T value) throw() {

            if(index == 0) {
                this->prepend(value);
                return;
            }
            else if(index == this->length) {
                this->append(value);
                return;
            }

            Node<T>* pre = this->traverse(index - 1);
            Node<T>* post = pre->next;

            Node<T>* node = new Node<T>(value);

            pre->next = node;
            node->next = post;

            this->length++;

        }

        void remove(int index) throw() {

            if(index == 0) {
                this->dropHead();
                return;
            }
            else if(index == this->length)
                throw index_out_of_bounds();

            Node<T>* pre = this->traverse(index - 1);
            Node<T>* garbageNode = pre->next;
            Node<T>* post = pre->next->next;

            garbageNode->next = NULL;
            pre->next = post;

            delete garbageNode;
            garbageNode = NULL;

            this->length--;

        }
};

#endif