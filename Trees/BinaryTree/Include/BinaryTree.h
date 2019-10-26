#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

template<class T>
class Node {
    private:
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
};

#endif