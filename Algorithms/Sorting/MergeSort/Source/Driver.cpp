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

    if(array.size() == 1)
        return array;

    vector<T> left, right;
    split(array, left, right);

    return merge(mergeSort(left), mergeSort(right));
}

template<typename T>
void split(vector<T> array, vector<T>& left, vector<T>& right) {

    int leftSize = array.size() / 2;

    left = vector<T>(array.begin(), array.begin() + leftSize);
    right = vector<T>(array.begin() + leftSize, array.end());

}

template<typename T>
vector<T> merge(vector<T> left, vector<T> right) {

    vector<T> array;

    typename vector<T>::iterator l = left.begin();
    typename vector<T>::iterator r = right.begin();

    while(l != left.end() && r != right.end()) {
        if(*r < *l) {
            array.push_back(*r);
            r++;
        }
        else {
            array.push_back(*l);
            l++;
        }
    }

    for(; l != left.end(); l++)
        array.push_back(*l);

    for(; r != right.end(); r++)
        array.push_back(*r);

    return array;
}