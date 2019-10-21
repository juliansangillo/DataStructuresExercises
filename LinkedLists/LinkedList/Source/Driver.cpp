#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    //LinkedList<int> list;
    DoublyLinkedList<int> list;

    list.append(10);
    list.append(15);
    list.prepend(5);

    list.insert(2, 999);
    list.remove(1);

    Node<int>* current1 = list.head;
    while(current1 != NULL) {
        cout << current1->getVal() << endl;
        current1 = current1->next;
    }
    cout << endl;

    cout << "Index 1 = " << list.find(1) << endl;

    cout << endl;

    DoubleNode<int>* current2 = static_cast<DoubleNode<int>*>(list.tail);
    while(current2 != NULL) {
        cout << current2->getVal() << endl;
        current2 = current2->prev;
    }
    cout << endl;

    cout << "Index 1 = " << list.find(1) << endl;

    return 0;
}