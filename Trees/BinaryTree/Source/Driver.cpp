#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {

    BinaryTree<int> tree;

    tree.insert(101);
    tree.insert(105);
    tree.insert(144);
    tree.insert(104);
    tree.insert(33);
    tree.insert(37);
    tree.insert(9);

    tree.print();
    cout << endl;

    Node<int>* node1 = tree.lookup(105);
    tree.printTree(node1, 1);
    cout << endl;

    Node<int>* node2 = tree.lookup(37);
    tree.printTree(node2, 1);
    cout << endl;

    Node<int>* node3 = tree.lookup(35);
    if(node3 != NULL)
        tree.printTree(node3, 1);
    else
        cout << "NULL" << endl;
    cout << endl;
    
    tree.remove(104);
    tree.print();
    cout << endl;

    /*tree.remove(144);
    tree.remove(37);
    tree.remove(9);
    tree.remove(33);
    tree.remove(105);
    tree.print();
    cout << endl;

    tree.remove(101);
    tree.print(); */

    return 0;
}