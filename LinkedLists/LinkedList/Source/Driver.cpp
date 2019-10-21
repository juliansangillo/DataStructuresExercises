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
    list.append(20);
    list.append(25);

    for(int i = 0; i < 2; i++) {
        Node<int>* current1 = list.head;
        while(current1 != NULL) {
            cout << current1->getVal() << endl;
            current1 = current1->next;
        }
        cout << endl;

        cout << "Index 3 = " << list.find(3) << endl << endl;

        cout << "Head = " << list.head->getVal() << endl;
        cout << "Tail = " << list.tail->getVal() << endl;

        cout << endl;

        DoubleNode<int>* current2 = static_cast<DoubleNode<int>*>(list.tail);
        while(current2 != NULL) {
            cout << current2->getVal() << endl;
            current2 = current2->prev;
        }
        cout << endl;

        cout << "Index 3 = " << list.find(3) << endl << endl;

        cout << "Head = " << list.head->getVal() << endl;
        cout << "Tail = " << list.tail->getVal() << endl;

        cout << endl;

        list.reverse();
    }

    return 0;
}