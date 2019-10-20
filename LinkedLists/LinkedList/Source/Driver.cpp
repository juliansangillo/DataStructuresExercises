#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList<int> list(10);

    list.append(15);
    list.prepend(5);

    list.insert(2, 999);
    list.remove(1);

    Node<int>* current = list.head;
    while(current != NULL) {
        cout << current->getVal() << endl;
        current = current->next;
    }
    cout << endl;

    cout << list.find(2);

    return 0;
}