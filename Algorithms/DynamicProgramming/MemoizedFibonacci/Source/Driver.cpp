#include <iostream>

using namespace std;

int fibonacci(int);

int main() {

    cout << fibonacci(10) << endl;

    return 0;
}

int fibonacci(int index) {

    if(index < 2)
        return index;

    return fibonacci(index - 2) + fibonacci(index - 1);
}