#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
vector<T> insertionSort(vector<T>);

int main() {

    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

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

    list<T> arrayList(array.begin(), array.end());

    typename list<T>::iterator i;
    for(i = next(arrayList.begin()); i != arrayList.end();) {
        typename list<T>::iterator j = i;
        
        while(j != arrayList.begin() && *prev(j) > *i)
            j = prev(j);

        if(j != i) {
            arrayList.insert(j, *i);
            i = arrayList.erase(i);
        }
        else
            i = next(i);
    }

    return vector<T>(arrayList.begin(), arrayList.end());
}