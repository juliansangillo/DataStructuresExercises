#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList<int> list(10);

    list.append(15);
    list.prepend(5);

    cout << list.head->getVal() << endl;
    cout << list.head->next->getVal() << endl;
    cout << list.head->next->next->getVal() << endl;
    cout << list.head->next->next->next << endl;

    return 0;
}