#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> bubbleSort(vector<T>);

int main() {

    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

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

    typename vector<T>::iterator pos;
    for(int sorted = 0; sorted < array.size(); sorted++)
        for(pos = array.begin(); pos < array.end() - (sorted + 1); pos++) {
            if(*pos > *(pos + 1)) {
                T temp = *pos;
                *pos = *(pos + 1);
                *(pos + 1) = temp;
            }
        }

    return array;
}