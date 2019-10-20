#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    //LinkedList<int> list;
    DoublyLinkedList<int> list;

    list.append(10);
    list.append(15);
    list.prepend(5);

    /* list.insert(2, 999);
    list.remove(1); */

    Node<int>* current = list.head;
    while(current != NULL) {
        cout << current->getVal() << endl;
        current = current->next;
    }
    cout << endl;
    
    cout << "Head = " << list.head->getVal() << "; Prev = " << static_cast<DoubleNode<int>*>(list.head)->prev << "; Next = " << list.head->next->getVal() << endl;
    cout << "Tail = " << list.tail->getVal() << "; Prev = " << static_cast<DoubleNode<int>*>(list.tail)->prev->getVal() << "; Next = " << list.tail->next << endl << endl;

    cout << list.find(2) << endl;

    return 0;
}