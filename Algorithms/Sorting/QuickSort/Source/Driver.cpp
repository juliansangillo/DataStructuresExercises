#include <iostream>
#include <vector>
#include <ctime>

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

    srand(time(NULL));

    vector<int> numbers = {232, 419, 370, 350, 318, 26, 312, 190, 211, 49, 488, 338, 348, 60, 16, 186, 268, 345, 457, 201, 87, 273, 
                            168, 449, 368, 289, 76, 31, 138, 114, 84, 160, 163, 239, 41, 427, 397, 266, 444, 291, 384, 7, 275, 148, 
                            45, 475, 250, 428, 169, 413, 121, 22, 0, 96, 295, 306, 155, 180, 329, 446, 470, 25, 343, 51, 396, 483, 
                            390, 23, 136, 52, 468, 277, 196, 64, 57, 67, 260, 479, 38, 98, 13, 480, 145, 1, 389, 188, 29, 192, 454, 
                            119, 131, 411, 224, 311, 137, 424, 271, 387, 39, 429};

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
    typename vector<T>::iterator i = array.begin();

    swapElements<T>(p, i);
    i = array.end() - 1;

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

    if(array.size() < 3)
        return array.begin();

    int index[3];
    int len = array.size();

    if(len == 3) {
        index[0] = 0;
        index[1] = 1;
        index[2] = 2;
    }
    else {
        index[0] = rand() % len;

        index[1] = rand() % len;
        while(index[1] == index[0])
            index[1] = rand() % len;

        index[2] = rand() % len;
        while(index[2] == index[1] || index[2] == index[0])
            index[2] = rand() % len;
    }

    typename vector<T>::iterator first = array.begin() + index[0];
    typename vector<T>::iterator second = array.begin() + index[1];
    typename vector<T>::iterator third = array.begin() + index[2];

    if((*first >= *second && *first < *third) || (*first >= *third && *first < *second))
        return first;
    else if((*second >= *first && *second < *third) || (*second >= *third && *second < *first))
        return second;
    else
        return third;
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