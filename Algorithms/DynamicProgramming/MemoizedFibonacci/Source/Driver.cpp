#include <iostream>

using namespace std;

int fibonacci(int, int&);

int main() {

    int cal = 0;
    
    cout << "Fib Answer: " << fibonacci(10, cal) << endl;
    cout << "Operations: " << cal << endl << endl;

    return 0;
}

int fibonacci(int index, int& cal) {

    if(index < 2)
        return index;

    cal++;
    return fibonacci(index - 2, cal) + fibonacci(index - 1, cal);
}