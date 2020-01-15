#include <iostream>
#include <unordered_map>

using namespace std;

int fibonacci(int, int&);
int memoizedFibonacci(int, unordered_map<int, int>&, int&);

int main() {

    int cal = 0;
    
    cout << "Fib Answer: " << fibonacci(10, cal) << endl;
    cout << "Operations: " << cal << endl << endl;

    unordered_map<int, int> memoize;
    cal = 0;

    cout << "Mem Answer: " << memoizedFibonacci(10, memoize, cal) << endl;
    cout << "Operations: " << cal << endl << endl;

    return 0;
}

int fibonacci(int index, int& cal) {

    if(index < 2)
        return index;

    cal++;
    return fibonacci(index - 2, cal) + fibonacci(index - 1, cal);
}

int memoizedFibonacci(int index, unordered_map<int, int>& memoize, int& cal) {

    if(index < 2)
        return index;

    if(memoize.find(index) == memoize.end()) {
        int result = memoizedFibonacci(index - 2, memoize, cal) + memoizedFibonacci(index - 1, memoize, cal);
        memoize.insert(make_pair(index, result));
        cal++;
    }

    return memoize[index];
}