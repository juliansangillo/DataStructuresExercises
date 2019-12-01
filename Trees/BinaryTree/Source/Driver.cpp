#include <iostream>

#include "AVLTree.h"

using namespace std;

int main() {

    AVLTree<int> tree;

    tree.insert(18);
    tree.print();
    cout << endl;
    
    tree.insert(3);
    tree.print();
    cout << endl;

    tree.insert(37);
    tree.print();
    cout << endl;

    tree.insert(2);
    tree.print();
    cout << endl;

    tree.insert(11);
    tree.print();
    cout << endl;

    tree.insert(25);
    tree.print();
    cout << endl;

    tree.insert(40);
    tree.print();
    cout << endl;

    tree.insert(1);
    tree.print();
    cout << endl;

    tree.insert(8);
    tree.print();
    cout << endl;

    tree.insert(13);
    tree.print();
    cout << endl;

    tree.insert(42);
    tree.print();
    cout << endl;

    tree.insert(6);
    tree.print();
    cout << endl;

    tree.insert(10);
    tree.print();
    cout << endl;

    tree.insert(15);
    tree.print();
    cout << endl;

    tree.insert(45);
    tree.print();
    cout << endl;

    tree.insert(-5);
    tree.print();
    cout << endl;

    tree.insert(5);
    tree.print();
    cout << endl;

    tree.insert(20);
    tree.print();
    cout << endl;

    tree.insert(23);
    tree.print();
    cout << endl;

    tree.insert(7);
    tree.print();
    cout << endl;

    tree.insert(4);
    tree.print();
    cout << endl;

    return 0;
}