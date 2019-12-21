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
        RedBlackNode(T data) : Node<T>(data) {

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
    private:
        void insertNode(RedBlackNode<T>* current, T data) {

            if(data < current->get()) {
                if(current->left == NULL) {
                    current->left = new RedBlackNode<T>(data);
                    return;
                }

                insertNode((RedBlackNode<T>*)current->left, data);
            }
            else if(data > current->get()) {
                if(current->right == NULL) {
                    current->right = new RedBlackNode<T>(data);
                    return;
                }

                insertNode((RedBlackNode<T>*)current->right, data);
            }
            else 
                throw duplicate_value_exception();

        }

        void initiateRemoval(T data) {

            Node<T>* targetParent;
            RedBlackNode<T>* target = (RedBlackNode<T>)this->lookupWithParent(data, targetParent);

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

        int isNotRedBlack(RedBlackNode<T>* tree) {

            if(tree->getColor() == BLACK) {
                if(tree->left != NULL && static_cast<RedBlackNode<T>*>(tree->left)->getColor() == RED)
                    if(tree->left->left != NULL && static_cast<RedBlackNode<T>*>(tree->left->left)->getColor() == RED)
                        return 1;
                    else if(tree->left->right != NULL && static_cast<RedBlackNode<T>*>(tree->left->right)->getColor() == RED)
                        return 2;
                
                if(tree->right != NULL && static_cast<RedBlackNode<T>*>(tree->right)->getColor() == RED)
                    if(tree->right->left != NULL && static_cast<RedBlackNode<T>*>(tree->right->left)->getColor() == RED)
                        return 3;
                    else if(tree->right->right != NULL && static_cast<RedBlackNode<T>*>(tree->right->right)->getColor() == RED)
                        return 4;
            }

            return 0;
        }

        void pushColorLeft(RedBlackNode<T>* node) {

            node->recolor();
            static_cast<RedBlackNode<T>*>(node->left)->recolor();

        }

        void pushColorRight(RedBlackNode<T>* node) {

            node->recolor();
            static_cast<RedBlackNode<T>*>(node->right)->recolor();

        }

        void pushColorDown(RedBlackNode<T>* node) {

            node->recolor();
            static_cast<RedBlackNode<T>*>(node->left)->recolor();
            static_cast<RedBlackNode<T>*>(node->right)->recolor();

        }

        RedBlackNode<T>* rotateLeft(RedBlackNode<T>* currentRoot) {

            RedBlackNode<T>* newRoot = (RedBlackNode<T>*)currentRoot->right;

            currentRoot->right = newRoot->left;
            newRoot->left = currentRoot;

            return newRoot;
        }

        RedBlackNode<T>* rotateRight(RedBlackNode<T>* currentRoot) {

            RedBlackNode<T>* newRoot = (RedBlackNode<T>*)currentRoot->left;

            currentRoot->left = newRoot->right;
            newRoot->right = currentRoot;

            return newRoot;
        }

        RedBlackNode<T>* rotateLeftRight(RedBlackNode<T>* currentRoot) {

            currentRoot->left = rotateLeft((RedBlackNode<T>*)currentRoot->left);
            RedBlackNode<T>* newRoot = rotateRight(currentRoot);

            return newRoot;
        }

        RedBlackNode<T>* rotateRightLeft(RedBlackNode<T>* currentRoot) {

            currentRoot->right = rotateRight((RedBlackNode<T>*)currentRoot->right);
            RedBlackNode<T>* newRoot = rotateLeft(currentRoot);
            
            return newRoot;
        }

        RedBlackNode<T>* correctSubTree(RedBlackNode<T>* tree, int status) {

            RedBlackNode<T>* newRoot = tree;

            switch(status) {
                case 1:
                    if(tree->right == NULL || static_cast<RedBlackNode<T>*>(tree->right)->getColor() == BLACK) {
                        newRoot = rotateRight(tree);
                        pushColorRight(newRoot);
                    }
                    else
                        pushColorDown(tree);
                    break;
                case 2:
                    if(tree->right == NULL || static_cast<RedBlackNode<T>*>(tree->right)->getColor() == BLACK) {
                        newRoot = rotateLeftRight(tree);
                        pushColorRight(newRoot);
                    }
                    else
                        pushColorDown(tree);
                    break;
                case 3:
                    if(tree->left == NULL || static_cast<RedBlackNode<T>*>(tree->left)->getColor() == BLACK) {
                        newRoot = rotateRightLeft(tree);
                        pushColorLeft(newRoot);
                    }
                    else
                        pushColorDown(tree);
                    break;
                case 4:
                    if(tree->left == NULL || static_cast<RedBlackNode<T>*>(tree->left)->getColor() == BLACK) {
                        newRoot = rotateLeft(tree);
                        pushColorLeft(newRoot);
                    }
                    else 
                        pushColorDown(tree);
                    break;
            }

            return newRoot;
        }

        void evaluateSubTree(RedBlackNode<T>* tree) {

            if(tree->left != NULL) {
                evaluateSubTree((RedBlackNode<T>*)tree->left);

                if(int status = isNotRedBlack((RedBlackNode<T>*)tree->left))
                    tree->left = correctSubTree((RedBlackNode<T>*)tree->left, status);
            }

            if(tree->right != NULL) {
                evaluateSubTree((RedBlackNode<T>*)tree->right);

                if(int status = isNotRedBlack((RedBlackNode<T>*)tree->right))
                    tree->right = correctSubTree((RedBlackNode<T>*)tree->right, status);
            }

        }
    public:
        RedBlackTree() : BinaryTree<T>() {}

        ~RedBlackTree() {}

        void insert(T data) {

            if(this->root == NULL)
                this->root = new RedBlackNode<T>(data);
            else
                insertNode((RedBlackNode<T>*)this->root, data);

            evaluateSubTree((RedBlackNode<T>*)this->root);

            if(int status = isNotRedBlack((RedBlackNode<T>*)this->root))
                    this->root = correctSubTree((RedBlackNode<T>*)this->root, status);

            if(static_cast<RedBlackNode<T>*>(this->root)->getColor() == RED)
                static_cast<RedBlackNode<T>*>(this->root)->recolor();

        }

        void remove(T data) {

            //initiateRemoval(data);

            evaluateSubTree((RedBlackNode<T>*)this->root);

            if(int status = isNotRedBlack((RedBlackNode<T>*)this->root))
                    this->root = correctSubTree((RedBlackNode<T>*)this->root, status);

            if(static_cast<RedBlackNode<T>*>(this->root)->getColor() == RED)
                static_cast<RedBlackNode<T>*>(this->root)->recolor();

        }

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
            if(root->getColor() == BLACK)
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