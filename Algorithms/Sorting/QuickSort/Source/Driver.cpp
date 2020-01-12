#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void split(vector<T>, typename vector<T>::iterator, vector<T>&, vector<T>&);
template<typename T>
typename vector<T>::iterator pivotOf(vector<T>);
template<typename T>
vector<T> quickSort(vector<T>);

int main() {

    vector<int> numbers = {6, 5, 3, 1, 8, 7, 2, 4};

    numbers = quickSort(numbers);

    typename vector<int>::iterator i;
    cout << "[";
    for(i = numbers.begin(); i != numbers.end(); i++)
        cout << "\t" << *i;
    cout << "\t]" << endl;

    return 0;
}

template<typename T>
vector<T> quickSort(vector<T> array) {



    return array;
}

template<typename T>
typename vector<T>::iterator pivotOf(vector<T> array) {

    return;
}

template<typename T>
void split(vector<T> array, typename vector<T>::iterator p, vector<T>& left, vector<T>& right) {

    

}