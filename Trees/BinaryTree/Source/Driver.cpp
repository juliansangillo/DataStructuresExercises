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

    return 0;
}