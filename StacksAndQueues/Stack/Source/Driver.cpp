#include <iostream>

#include "Stack.h"

using namespace std;

int main() {

    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(25);
    stack.push(40);
    stack.push(999);
    //stack.push(1000);

    cout << "Peek: " << stack.peek() << endl << endl;

    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl << endl;
    //cout << "Pop: " << stack.pop() << endl;

    //cout << "Peek: " << stack.peek() << endl;

    return 0;
}