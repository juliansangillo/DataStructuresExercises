#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> bubbleSort(vector<T>);

int main() {

    vector<int> numbers = {6, 5, 3, 1, 8, 7, 2, 4};

    numbers = bubbleSort(numbers);

    typename vector<int>::iterator i;
    cout << "[";
    for(i = numbers.begin(); i != numbers.end(); i++)
        cout << "\t" << *i;
    cout << "\t]" << endl;

    return 0;
}

template<typename T>
vector<T> bubbleSort(vector<T> array) {

    //Perform bubble sort on array

    return array;
}