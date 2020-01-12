#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void split(vector<T>&, typename vector<T>::iterator, vector<T>&, vector<T>&);
template<typename T>
void swapElements(typename vector<T>::iterator&, typename vector<T>::iterator&);
template<typename T>
typename vector<T>::iterator pivotOf(vector<T>&);
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

    if(array.size() == 1)
        return array;

    typename vector<T>::iterator p = pivotOf(array);
    typename vector<T>::iterator i = array.end() - 1;

    while(i != p) {
        if(i > p) {
            if(*i < *p) {
                swapElements<T>(p, i);
                i++;

                continue;
            }

            i--;
        }
        else if(i < p) {
            if(*i > *p) {
                swapElements<T>(p, i);
                i--;

                continue;
            }

            i++;
        }
    }

    vector<T> left, right;
    split(array, p, left, right);

    if(!left.empty())
        left = quickSort(left);
    if(!right.empty())
        right = quickSort(right);

    array = left;
    array.push_back(*p);
    array.insert(array.end(), right.begin(), right.end());

    return array;
}

template<typename T>
typename vector<T>::iterator pivotOf(vector<T>& array) {

    return array.begin();
}

template<typename T>
void swapElements(typename vector<T>::iterator& p, typename vector<T>::iterator& i) {

    typename vector<T>::iterator t = p;
    p = i;
    i = t;

    T temp = *p;
    *p = *i;
    *i = temp;

}

template<typename T>
void split(vector<T>& array, typename vector<T>::iterator p, vector<T>& left, vector<T>& right) {

    left = vector<T>(array.begin(), p);
    right = vector<T>(p + 1, array.end());

}