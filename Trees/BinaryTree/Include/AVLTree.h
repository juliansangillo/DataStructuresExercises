#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "BinaryTree.h"

template<class T>
class AVLNode : public Node<T> {
    private:
        int height;
    public:
        AVLNode(T data) : Node<T>(data) {

            this->height = 1;

        }

        ~AVLNode() {}

        void incrementHeight() {

            this->height++;

        }
        
        int getHeight() {

            return this->height;
        }

        void setHeight(int height) {

            this->height = height;

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

        void evaluateAndCorrectHeight(AVLNode<T>* node) {

            int greatestChildHeight;
            if(node->left != NULL && node->right != NULL)
                if(((AVLNode<T>*)node->left)->getHeight() > ((AVLNode<T>*)node->right)->getHeight())
                    greatestChildHeight = ((AVLNode<T>*)node->left)->getHeight();
                else
                    greatestChildHeight = ((AVLNode<T>*)node->right)->getHeight();
            else if(node->left != NULL)
                greatestChildHeight = ((AVLNode<T>*)node->left)->getHeight();
            else if(node->right != NULL)
                greatestChildHeight = ((AVLNode<T>*)node->right)->getHeight();
            else
                greatestChildHeight = 0;

            node->setHeight(greatestChildHeight + 1);

        }

        AVLNode<T>* rotateLeft(AVLNode<T>* currentRoot) {

            AVLNode<T>* newRoot = (AVLNode<T>*)currentRoot->right;

            currentRoot->right = newRoot->left;
            newRoot->left = currentRoot;

            evaluateAndCorrectHeight(currentRoot);
            evaluateAndCorrectHeight(newRoot);

            return newRoot;
        }

        AVLNode<T>* rotateRight(AVLNode<T>* currentRoot) {

            AVLNode<T>* newRoot = (AVLNode<T>*)currentRoot->left;

            currentRoot->left = newRoot->right;
            newRoot->right = currentRoot;

            evaluateAndCorrectHeight(currentRoot);
            evaluateAndCorrectHeight(newRoot);

            return newRoot;
        }

        AVLNode<T>* rotateLeftRight(AVLNode<T>* currentRoot) {

            currentRoot->left = rotateLeft((AVLNode<T>*)currentRoot->left);
            AVLNode<T>* newRoot = rotateRight(currentRoot);

            return newRoot;
        }

        AVLNode<T>* rotateRightLeft(AVLNode<T>* currentRoot) {

            currentRoot->right = rotateRight((AVLNode<T>*)currentRoot->right);
            AVLNode<T>* newRoot = rotateLeft(currentRoot);
            
            return newRoot;
        }

        AVLNode<T>* evaluateAndCorrectSubTree(AVLNode<T>* subTree) {

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

                    current->left = evaluateAndCorrectSubTree((AVLNode<T>*)current->left);
                }

                if(((AVLNode<T>*)current->left)->getHeight() == current->getHeight())
                    current->incrementHeight();
            }
            else if(data > current->get()) {
                if(current->right == NULL)
                    current->right = new AVLNode<T>(data);
                else {
                    insertNode((AVLNode<T>*)current->right, data);

                    current->right = evaluateAndCorrectSubTree((AVLNode<T>*)current->right);
                }

                if(((AVLNode<T>*)current->right)->getHeight() == current->getHeight())
                    current->incrementHeight();
            }
            else
                throw duplicate_value_exception();

        }

        void deleteFoundTarget(AVLNode<T>* target, AVLNode<T>* targetParent) {

            if(target->left != NULL && target->right != NULL) {
                Node<T>* successorParent;
                Node<T>* successor = this->successorOf(target, successorParent);

                int height = target->getHeight();

                this->deleteNode(target, targetParent, target->left, target->right, successor, successorParent);
                if(successor->right != NULL)
                    successor->right = evaluateAndCorrectSubTree((AVLNode<T>*)successor->right);

                ((AVLNode<T>*)successor)->setHeight(height);
            }
            else if(target->left != NULL)
                this->deleteNode(target, targetParent, target->left);
            else if(target->right != NULL)
                this->deleteNode(target, targetParent, target->right);
            else
                this->deleteNode(target, targetParent);

        }

        void removeNode(AVLNode<T>* current, T data) {

            if(data < current->get()) {
                if(current->left == NULL)
                    throw node_not_found_exception();
                else if(data == current->left->get())
                    deleteFoundTarget((AVLNode<T>*)current->left, current);
                else
                    removeNode((AVLNode<T>*)current->left, data);

                if(current->left != NULL) {
                    current->left = evaluateAndCorrectSubTree((AVLNode<T>*)current->left);
                    evaluateAndCorrectHeight((AVLNode<T>*)current->left);
                }
            }
            else if(data > current->get()) {
                if(current->right == NULL)
                    throw node_not_found_exception();
                else if(data == current->right->get())
                    deleteFoundTarget((AVLNode<T>*)current->right, current);
                else
                    removeNode((AVLNode<T>*)current->right, data);

                if(current->right != NULL) {
                    current->right = evaluateAndCorrectSubTree((AVLNode<T>*)current->right);
                    evaluateAndCorrectHeight((AVLNode<T>*)current->right);
                }
            }

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
            
            this->root = this->evaluateAndCorrectSubTree((AVLNode<T>*)this->root);

        }
        
        void remove(T data) {

            if(this->root == NULL)
                throw node_not_found_exception();

            if(data == this->root->get())
                this->deleteFoundTarget((AVLNode<T>*)this->root, NULL);
            else
                this->removeNode((AVLNode<T>*)this->root, data);

            this->root = this->evaluateAndCorrectSubTree((AVLNode<T>*)this->root);
            evaluateAndCorrectHeight((AVLNode<T>*)this->root);

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