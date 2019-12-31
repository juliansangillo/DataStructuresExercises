#include <iostream>

using namespace std;

int fibonacciIterative(int);
int fibonacciRecursive(int);

int main() {

    cout << "Iterative: " << fibonacciIterative(10) << endl;
    cout << "Recursive: " << fibonacciRecursive(2) << endl;

    return 0;
}

int fibonacciIterative(int index) {

    int prev = 0;
    int current = 1;

    if(index == 0)
        return prev;
    
    if(index == 1)
        return current;

    for(int i = 2; i <= index; i++) {
        int next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

int fibonacciRecursive(int index) {

    //TODO Recursive code goes here

    return 0;
}