#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> merge(vector<T>, vector<T>);
template<typename T>
void split(vector<T>, vector<T>&, vector<T>&);
template<typename T>
vector<T> mergeSort(vector<T>);

int main() {

    vector<int> numbers = {6, 5, 3, 1, 8, 7, 2, 4};

    numbers = mergeSort(numbers);

    typename vector<int>::iterator i;
    cout << "[";
    for(i = numbers.begin(); i != numbers.end(); i++)
        cout << "\t" << *i;
    cout << "\t]" << endl;

    return 0;
}

template<typename T>
vector<T> mergeSort(vector<T> array) {


    return array;
}

template<typename T>
void split(vector<T> array, vector<T>& left, vector<T>& right) {



}

template<typename T>
vector<T> merge(vector<T> left, vector<T> right) {

    vector<T> array;

    return array;
}