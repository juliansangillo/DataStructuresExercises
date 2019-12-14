#ifndef __REDBLACKTREE_H__
#define __REDBLACKTREE_H__

#include "BinaryTree.h"

#define BLACK true
#define RED false

template<class T>
class RedBlackNode : public Node<T> {
    private:
        bool color;
    public:
        RedBlackNode(T data) : BinaryTree<T>(data) {

            this->color = RED;

        }

        ~RedBlackNode() {}

        void recolor() {

            this->color = !this->color;

        }

        bool getColor() {

            return this->color;
        }
};

template<class T>
class RedBlackTree : public BinaryTree<T> {
    public:
        RedBlackTree() : BinaryTree<T> {}

        ~RedBlackTree() {}

        void insert(T data) {}

        void remove(T data) {}

        void print() {

            std::cout << "Root: ";
            if(this->root == NULL) {
                std::cout << "NULL" << std::endl;
                return;
            }

            printTree((RedBlackNode<T>*)this->root, 1);

        }

        void printTree(RedBlackNode<T>* root, T level) {

            std::cout << root->get() << " {" << std::endl;

            for(int i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Color: ";
            if(root->color == BLACK)
                std::cout << "BLACK" << std::endl;
            else
                std::cout << "RED" << std::endl;
            
            for(int i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Left: ";
            if(root->left == NULL)
                std::cout << "NULL" << std::endl;
            else
                printTree((RedBlackNode<T>*)root->left, level+1);

            for(int i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Right: ";
            if(root->right == NULL)
                std::cout << "NULL" << std::endl;
            else
                printTree((RedBlackNode<T>*)root->right, level+1);

            for(int i = 0; i < level - 1; i++)
                std::cout << "\t";
            std::cout << "}" << std::endl;

        }
};

#endif