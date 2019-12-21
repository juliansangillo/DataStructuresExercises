#include <iostream>

//#include "AVLTree.h"
#include "RedBlackTree.h"

using namespace std;

int main() {

    RedBlackTree<int> tree;

    tree.insert(50);
    tree.print();
    cout << endl;

    tree.insert(40);
    tree.print();
    cout << endl;

    tree.insert(60);
    tree.print();
    cout << endl;

    tree.insert(20);
    tree.print();
    cout << endl;

    tree.insert(45);
    tree.print();
    cout << endl;

    tree.insert(55);
    tree.print();
    cout << endl;

    tree.insert(70);
    tree.print();
    cout << endl;

    tree.insert(15);
    tree.print();
    cout << endl;

    tree.insert(25);
    tree.print();
    cout << endl;

    tree.insert(52);
    tree.print();
    cout << endl;

    tree.insert(58);
    tree.print();
    cout << endl;

    tree.insert(80);
    tree.print();
    cout << endl;

    tree.insert(56);
    tree.print();
    cout << endl;

    tree.insert(100);
    tree.print();
    cout << endl;

    tree.insert(51);
    tree.print();
    cout << endl;

    tree.insert(54);
    tree.print();
    cout << endl;

    tree.insert(53);
    tree.print();
    cout << endl;

    tree.insert(57);
    tree.print();
    cout << endl;

    tree.insert(19);
    tree.print();
    cout << endl;

    tree.insert(16);
    tree.print();
    cout << endl;

    tree.insert(10);
    tree.print();
    cout << endl;

    //Redo remove
    tree.remove(10);
    tree.print();
    cout << endl;

    tree.remove(54); //BUG: Does not update node color
    tree.print();
    cout << endl;
    
    return 0;
}