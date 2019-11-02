#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "BinaryTree.h"

template<class T>
class AVLNode : public Node<T> {
    private:
        int height;
    public:
        AVLNode(int height, T data) : Node(data) {

            this->height = height;

        }

        ~AVLNode() {}

        void setHeight(int height) {

            this->height = height;

        }
        
        int getHeight() {

            return this->height;
        }
};

template<class T>
class AVLTree : public BinaryTree<T> {
    private:
        AVLNode<T>* rotateLeft(AVLNode<T>* currentRoot) {



            return NULL;
        }

        AVLNode<T>* rotateRight(AVLNode<T>* currentRoot) {

            

            return NULL;
        }

        bool insertNode(AVLNode<T>* current, T data) {



            return false;
        }
    public:
        AVLTree() : BinaryTree() {}

        ~AVLTree() {}

        void insert(T data) {

            

        }
};

#endif