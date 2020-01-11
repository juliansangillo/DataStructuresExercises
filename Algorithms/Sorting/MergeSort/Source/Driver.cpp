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

    vector<int> numbers = {232, 419, 370, 350, 318, 26, 312, 190, 211, 49, 488, 338, 348, 60, 16, 186, 268, 345, 457, 201, 87, 273, 
                            168, 449, 368, 289, 76, 31, 138, 114, 84, 160, 163, 239, 41, 427, 397, 266, 444, 291, 384, 7, 275, 148, 
                            45, 475, 250, 428, 169, 413, 121, 22, 0, 96, 295, 306, 155, 180, 329, 446, 470, 25, 343, 51, 396, 483, 
                            390, 23, 136, 52, 468, 277, 196, 64, 57, 67, 260, 479, 38, 98, 13, 480, 145, 1, 389, 188, 29, 192, 454, 
                            119, 131, 411, 224, 311, 137, 424, 271, 387, 39, 429};

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