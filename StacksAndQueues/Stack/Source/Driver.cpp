#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

    Stack<int> stack;

    stack.push(5);
    stack.testPrint();
    stack.push(10);
    stack.testPrint();
    stack.push(25);
    stack.testPrint();
    stack.push(40);
    stack.testPrint();
    stack.push(999);
    stack.testPrint();

    cout << "Pop: " << stack.pop() << endl << endl;
    stack.testPrint();
    cout << "Pop: " << stack.pop() << endl << endl;
    stack.testPrint();
    cout << "Pop: " << stack.pop() << endl << endl;
    stack.testPrint();

    return 0;
}