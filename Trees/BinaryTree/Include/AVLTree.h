#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "BinaryTree.h"

template<class T>
class AVLNode : public Node<T> {
    private:
        T height;
    public:
        AVLNode(T data) : Node<T>(data) {

            this->height = 1;

        }

        ~AVLNode() {}

        void incrementHeight() {

            this->height++;

        }

        void decrementHeightBy(T amount) {

            this->height -= amount;

        }
        
        T getHeight() {

            return this->height;
        }
};

template<class T>
class AVLTree : public BinaryTree<T> {
    private:
        T calculateBalance(AVLNode<T>* tree) {

            if(tree->left != NULL && tree->right != NULL)
                return ((AVLNode<T>*)tree->right)->getHeight() - ((AVLNode<T>*)tree->left)->getHeight();
            else if(tree->right != NULL)
                return ((AVLNode<T>*)tree->right)->getHeight();
            else if(tree->left != NULL)
                return -((AVLNode<T>*)tree->left)->getHeight();
            return 0;
        }

        AVLNode<T>* rotateLeft(AVLNode<T>* currentRoot, T decAmount = 2) {

            AVLNode<T>* newRoot = (AVLNode<T>*)currentRoot->right;

            currentRoot->right = newRoot->left;
            newRoot->left = currentRoot;

            currentRoot->decrementHeightBy(decAmount);

            return newRoot;
        }

        AVLNode<T>* rotateRight(AVLNode<T>* currentRoot, T decAmount = 2) {

            AVLNode<T>* newRoot = (AVLNode<T>*)currentRoot->left;

            currentRoot->left = newRoot->right;
            newRoot->right = currentRoot;

            currentRoot->decrementHeightBy(decAmount);

            return newRoot;
        }

        AVLNode<T>* rotateLeftRight(AVLNode<T>* currentRoot) {

            currentRoot->left = rotateLeft((AVLNode<T>*)currentRoot->left, 1);
            AVLNode<T>* newRoot = rotateRight(currentRoot);

            newRoot->incrementHeight();

            return newRoot;
        }

        AVLNode<T>* rotateRightLeft(AVLNode<T>* currentRoot) {

            currentRoot->right = rotateRight((AVLNode<T>*)currentRoot->right, 1);
            AVLNode<T>* newRoot = rotateLeft(currentRoot);

            newRoot->incrementHeight();
            
            return newRoot;
        }

        AVLNode<T>* evaluateAndCorrectSubTree(AVLNode<T>* subTree, T data) {

            int balanceFactor = calculateBalance(subTree);

            AVLNode<T>* child;
            AVLNode<T>* newTree = subTree;
            if(balanceFactor < -1) {
                balanceFactor = calculateBalance((AVLNode<T>*)subTree->left);
                
                if(balanceFactor > 0)
                    newTree = rotateLeftRight(subTree);
                else
                    newTree = rotateRight(subTree);
            }
            else if(balanceFactor > 1) {
                balanceFactor = calculateBalance((AVLNode<T>*)subTree->right);
                
                if(balanceFactor < 0)
                    newTree = rotateRightLeft(subTree);
                else
                    newTree = rotateLeft(subTree);
            }

            return newTree;
        }

        void insertNode(AVLNode<T>* current, T data) {

            if(data < current->get()) {
                if(current->left == NULL)
                    current->left = new AVLNode<T>(data);
                else {
                    insertNode((AVLNode<T>*)current->left, data);

                    current->left = evaluateAndCorrectSubTree((AVLNode<T>*)current->left, data);
                }

                if(((AVLNode<T>*)current->left)->getHeight() == current->getHeight())
                    current->incrementHeight();
            }
            else if(data > current->get()) {
                if(current->right == NULL)
                    current->right = new AVLNode<T>(data);
                else {
                    insertNode((AVLNode<T>*)current->right, data);

                    current->right = evaluateAndCorrectSubTree((AVLNode<T>*)current->right, data);
                }

                if(((AVLNode<T>*)current->right)->getHeight() == current->getHeight())
                    current->incrementHeight();
            }
            else
                throw duplicate_value_exception();

        }
    public:
        AVLTree() : BinaryTree<T>() {}

        ~AVLTree() {}

        void insert(T data) {

            if(this->root == NULL) {
                this->root = new AVLNode<T>(data);
                return;
            }

            this->insertNode((AVLNode<T>*)this->root, data);
            
            this->root = this->evaluateAndCorrectSubTree((AVLNode<T>*)this->root, data);

        }

        void print() {

            std::cout << "Root: ";
            if(this->root == NULL) {
                std::cout << "NULL" << std::endl;
                return;
            }

            printTree((AVLNode<T>*)this->root, 1);

        }

        void printTree(AVLNode<T>* root, T level) {

            std::cout << root->get() << " {" << std::endl;

            for(T i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Height: " << ((AVLNode<T>*)root)->getHeight() << std::endl;
            
            for(T i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Left: ";
            if(root->left == NULL)
                std::cout << "NULL" << std::endl;
            else
                printTree((AVLNode<T>*)root->left, level+1);

            for(T i = 0; i < level; i++)
                std::cout << "\t";
            std::cout << "Right: ";
            if(root->right == NULL)
                std::cout << "NULL" << std::endl;
            else
                printTree((AVLNode<T>*)root->right, level+1);

            for(T i = 0; i < level - 1; i++)
                std::cout << "\t";
            std::cout << "}" << std::endl;

        }
};

#endif