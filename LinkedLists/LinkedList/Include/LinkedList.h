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
    protected:
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

        void removeHead() {

            Node<T>* garbage = head;
            head = head->next;

            delete garbage;
            garbage = NULL;

            this->length--;

        }
    public:
        Node<T>* head;
        Node<T>* tail;

        LinkedList() {

            head = NULL;
            tail = NULL;

            this->length = 0;

        }

        ~LinkedList() {

            while(head != NULL)
                this->removeHead();

            tail = NULL;
        }

        void prepend(T value) {

            Node<T>* node = new Node<T>(value);

            if(head != NULL)
                node->next = head;
            else
                tail = node;
            head = node;

            this->length++;

        }

        void append(T value) {

            Node<T>* node = new Node<T>(value);

            if(tail != NULL)
                tail->next = node;
            else
                head = node;
            tail = node;

            this->length++;

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
                this->removeHead();
                return;
            }
            else if(index == this->length)
                throw index_out_of_bounds();

            Node<T>* pre = this->traverse(index - 1);
            Node<T>* garbageNode = pre->next;
            Node<T>* post = pre->next->next;

            garbageNode->next = NULL;
            pre->next = post;

            if(garbageNode == tail) {
                tail = pre;
            }

            delete garbageNode;
            garbageNode = NULL;

            this->length--;

        }

        void reverse() {

            if(this->length == 0 || this->length == 1)
                return;

            Node<T>* pt1;
            Node<T>* pt2;
            Node<T>* pt3;

            pt1 = head;
            pt2 = head->next;
            
            head->next = NULL;
            do {
                pt3 = pt2->next;
                pt2->next = pt1;
                pt1 = pt2;
                pt2 = pt3;
            } while(pt3 != NULL);

            pt1 = head;
            head = tail;
            tail = pt1;

        }
};

template<class T>
class DoubleNode : public Node<T> {
    public:
        DoubleNode<T>* prev;

        DoubleNode(T value) : Node<T>::Node(value) {

            this->prev = NULL;

        }

        ~DoubleNode() {

            this->prev = NULL;

        }
};

template<class T>
class DoublyLinkedList : public LinkedList<T> {
    private:
        DoubleNode<T>* reverseTraverse(int index) const throw() {

            if(index < 0)
                throw negative_index_exception();
            else if(index >= this->length)
                throw index_out_of_bounds();

            DoubleNode<T>* current = static_cast<DoubleNode<T>*>(this->tail);
            int counter = this->length - 1;
            while(counter != index) {
                current = current->prev;
                counter--;
            }

            return current;

        }

        bool isInFront(int index) const {

            int mid;
            if(this->length % 2)
                mid = this->length / 2;
            else
                mid = (this->length - 1) / 2;

            if(index <= mid)
                return true;
            else
                return false;    
        }
    public:
        DoublyLinkedList() : LinkedList<T>::LinkedList() {}

        void prepend(T value) {

            DoubleNode<T>* node = new DoubleNode<T>(value);

            if(this->head != NULL) {
                node->next = this->head;
                static_cast<DoubleNode<T>*>(this->head)->prev = node;
            }
            else
                this->tail = node;
            this->head = node;

            this->length++;

        }

        void append(T value) {

            DoubleNode<T>* node = new DoubleNode<T>(value);

            if(this->tail != NULL) {
                this->tail->next = node;
                node->prev = static_cast<DoubleNode<T>*>(this->tail);
            }
            else
                this->head = node;
            this->tail = node;

            this->length++;

        }

        T find(int index) const throw() {

            if(this->isInFront(index))
                return this->traverse(index)->getVal();
            else
                return this->reverseTraverse(index)->getVal();
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

            DoubleNode<T>* post;
            if(this->isInFront(index - 1))
                post = static_cast<DoubleNode<T>*>(this->traverse(index));
            else
                post = this->reverseTraverse(index);
            DoubleNode<T>* pre = post->prev;

            DoubleNode<T>* node = new DoubleNode<T>(value);

            pre->next = node;
            node->prev = pre;
            node->next = post;
            post->prev = node;

            this->length++;

        }

        void remove(int index) throw() {

            if(index == 0) {
                this->removeHead();
                return;
            }
            else if(index == this->length)
                throw index_out_of_bounds();

            DoubleNode<T>* garbageNode;
            if(this->isInFront(index))
                garbageNode = static_cast<DoubleNode<T>*>(this->traverse(index));
            else
                garbageNode = this->reverseTraverse(index);
            DoubleNode<T>* pre = garbageNode->prev;
            DoubleNode<T>* post = static_cast<DoubleNode<T>*>(garbageNode->next);

            garbageNode->next = NULL;
            garbageNode->prev = NULL;
            pre->next = post;
            if(post != NULL)
                post->prev = pre;

            if(garbageNode == this->tail) {
                this->tail = pre;
            }

            delete garbageNode;
            garbageNode = NULL;

            this->length--;

        }

        void reverse() {

            if(this->length == 0 || this->length == 1)
                return;

            DoubleNode<T>* pt1;
            DoubleNode<T>* pt2;

            pt1 = static_cast<DoubleNode<T>*>(this->head);
            pt2 = static_cast<DoubleNode<T>*>(this->head->next);
            
            this->head->next = NULL;
            static_cast<DoubleNode<T>*>(this->head)->prev = pt2;
            do {
                pt2->prev = static_cast<DoubleNode<T>*>(pt2->next);
                pt2->next = pt1;
                pt1 = pt2;
                pt2 = pt2->prev;
            } while(pt2 != NULL);

            pt1 = static_cast<DoubleNode<T>*>(this->head);
            this->head = this->tail;
            this->tail = pt1;

        }
};

#endif