#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void swapElements(typename vector<T>::iterator, typename vector<T>::iterator);
template<typename T>
typename vector<T>::iterator scanForSmallest(typename vector<T>::iterator, typename vector<T>::iterator);
template<typename T>
vector<T> selectionSort(vector<T>);

int main() {

    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    numbers = selectionSort(numbers);

    typename vector<int>::iterator i;
    cout << "[";
    for(i = numbers.begin(); i != numbers.end(); i++)
        cout << "\t" << *i;
    cout << "\t]" << endl;

    return 0;
}

template<typename T>
vector<T> selectionSort(vector<T> array) {

    for(int sorted = 0; sorted < array.size() - 1; sorted++) {
        typename vector<T>::iterator first = array.begin() + sorted;
        typename vector<T>::iterator smallest = scanForSmallest<T>(first, array.end());

        swapElements<T>(first, smallest);
    }
    
    return array;
}

template<typename T>
typename vector<T>::iterator scanForSmallest(typename vector<T>::iterator first, typename vector<T>::iterator last) {

    typename vector<T>::iterator smallest = first;

    typename vector<T>::iterator pos;
    for(pos = first + 1; pos != last; pos++)
        if(*pos < *smallest)
            smallest = pos;

    return smallest;
}

template<typename T>
void swapElements(typename vector<T>::iterator first, typename vector<T>::iterator smallest) {

    T temp = *first;
    *first = *smallest;
    *smallest = temp;

}