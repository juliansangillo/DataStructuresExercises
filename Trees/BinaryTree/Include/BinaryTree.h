#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include "Exception.h"

template<class T>
class Node {
    protected:
        T data;
    public:
        Node<T>* left;
        Node<T>* right;

        Node(T data) {

            this->data = data;
            left = NULL;
            right = NULL;

        }

        ~Node() {

            if(left != NULL) {
                delete left;
                left = NULL;
            }
            
            if(right != NULL) {
                delete right;
                right = NULL;
            }

        }

        void set(T data) {

            this->data = data;

        }

        T get() {

            return data;
        }
};

template<class T>
class BinaryTree {
    protected:
        Node<T>* lookupWithParent(T data, Node<T>*& parent) {

            Node<T>* current = root;
            parent = NULL;

            while(current != NULL)
                if(data < current->get()) {
                    parent = current;
                    current = current->left;
                }
                else if(data > current->get()) {
                    parent = current;
                    current = current->right;
                }
                else
                    return current;
                    
            return NULL;
        }

        Node<T>* successorOf(Node<T>* node, Node<T>*& parent) {

            parent = node;
            Node<T>* current = node->right;

            while(current->left != NULL) {
                parent = current;
                current = current->left;
            }

            return current;
        }

        //WAYS TO DELETENODE()
        //Given just the target and parent; delete the leaf node and nullify parent pointer
        void deleteNode(Node<T>* target, Node<T>* targetParent) {

            if(targetParent != NULL)
                if(targetParent->left == target)
                    targetParent->left = NULL;
                else
                    targetParent->right = NULL;
            else
                root = NULL;

            delete target;
            target = NULL;

        }

        //Given the target, parent, and one child; bypass the target and delete it
        void deleteNode(Node<T>* target, Node<T>* targetParent, Node<T>* child) {

            if(targetParent != NULL)
                if(targetParent->left == target)
                    targetParent->left = child;
                else
                    targetParent->right = child;
            else
                root = child;

            if(target->left == child)
                target->left = NULL;
            else
                target->right = NULL;

            delete target;
            target = NULL;

        }

        //Given the target, parent, two children, a successor, and its parent; switch pointers from target to successor, replacing it, and delete target
        void deleteNode(Node<T>* target, Node<T>* targetParent, Node<T>* leftChild, Node<T>* rightChild, Node<T>* successor, Node<T>* successorParent) {

            target->left = NULL;
            target->right = NULL;

            if(targetParent != NULL)
                if(targetParent->left == target)
                    targetParent->left = successor;
                else
                    targetParent->right = successor;
            else
                root = successor;

            if(rightChild == successor)
                successor->left = leftChild;
            else {
                successorParent->left = successor->right;
                successor->left = leftChild;
                successor->right = rightChild;
            }
            
            delete target;
            target = NULL;

        }
    public:
        Node<T>* root;

        BinaryTree() {

            root = NULL;

        }

        ~BinaryTree() {

            if(root != NULL) {
                delete root;
                root = NULL;
            }

        }

        void insert(T data) {

            if(root == NULL) {
                root = new Node<T>(data);
                return;
            }

            Node<T>* current = root;

            while(true) {
                if(data < current->get()) {
                    if(current->left == NULL) {
                        current->left = new Node<T>(data);
                        return;
                    }

                    current = current->left;
                }
                else if(data > current->get()) {
                    if(current->right == NULL) {
                        current->right = new Node<T>(data);
                        return;
                    }

                    current = current->right;
                }
                else
                    throw duplicate_value_exception();
            }

        }

        Node<T>* lookup(T data) {

            Node<T>* current = root;

            while(current != NULL)
                if(data < current->get())
                    current = current->left;
                else if(data > current->get())
                    current = current->right;
                else
                    return current;
                    
            return NULL;
        }

        void remove(T data) {

            Node<T>* targetParent;
            Node<T>* target = this->lookupWithParent(data, targetParent);

            if(target == NULL)
                throw node_not_found_exception();

            if(target->left != NULL && target->right != NULL) {
                Node<T>* successorParent;
                Node<T>* successor = this->successorOf(target, successorParent);

                this->deleteNode(target, targetParent, target->left, target->right, successor, successorParent);
            }
            else if(target->left != NULL)
                this->deleteNode(target, targetParent, target->left);
            else if(target->right != NULL)
                this->deleteNode(target, targetParent, target->right);
            else
                this->deleteNode(target, targetParent);

        }

        void print() {

            std::cout << "Root: ";
            if(root == NULL) {
                std::cout << "NULL" << std::endl;
                return;
            }

            printTree(root, 1);

        }

        void printTree(Node<T>* root, int level) {

            std::cout << root->get() << " {" << std::endl;
            
            for(int i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Left: ";
            if(root->left == NULL)
                std::cout << "NULL" << std::endl;
            else
                printTree(root->left, level+1);

            for(int i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Right: ";
            if(root->right == NULL)
                std::cout << "NULL" << std::endl;
            else
                printTree(root->right, level+1);

            for(int i = 0; i < level - 1; i++)
                std::cout << "\t";
            std::cout << "}" << std::endl;

        }
};

#endif