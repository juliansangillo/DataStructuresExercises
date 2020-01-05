#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> insertionSort(vector<T>);

int main() {

    vector<int> numbers = {6, 5, 3, 1, 8, 7, 2, 4};

    numbers = insertionSort(numbers);

    typename vector<int>::iterator i;
    cout << "[";
    for(i = numbers.begin(); i != numbers.end(); i++)
        cout << "\t" << *i;
    cout << "\t]" << endl;

    return 0;
}

template<typename T>
vector<T> insertionSort(vector<T> array) {

    //Insertion Sort code goes here

    return array;
}