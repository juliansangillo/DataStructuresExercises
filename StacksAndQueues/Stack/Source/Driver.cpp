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

    stack.testPrint();

    return 0;
}