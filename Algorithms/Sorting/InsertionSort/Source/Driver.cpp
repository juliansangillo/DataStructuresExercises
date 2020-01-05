#include <iostream>
#include <vector>
#include <list>

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