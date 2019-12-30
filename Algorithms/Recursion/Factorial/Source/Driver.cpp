#include <iostream>

using namespace std;

int factorialIterative(int);
int factorialRecursive(int);

int main() {

    cout << "Iterative: " << factorialIterative(5) << endl;
    cout << "Recursive: " << factorialRecursive(5) << endl;

    return 0;
}

int factorialIterative(int num) {

    unsigned long total = 1;

    for(int i = num; i > 1; i--)
        total *= i;
    
    return total;
}

int factorialRecursive(int num) {

    //TODO Recursive code goes here

    return 0;
}