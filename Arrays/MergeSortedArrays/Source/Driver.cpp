#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>, vector<int>);
void mergeInto(vector<int>&, vector<int>::iterator&);

int main()
{

    vector<int> arr1{0, 3, 4, 31};
    vector<int> arr2{4, 6, 30};

    vector<int> merged = merge(arr1, arr2);

    stringstream sstr;
    string str;

    sstr << "[";
    for(int num : merged)
        sstr << num << ", ";
    str = sstr.str();
    str.pop_back();
    str.pop_back();
    str.append("]");

    cout << str << endl;

    return 0;
}

vector<int> merge(vector<int> arr1, vector<int> arr2) {

    if(arr2.size() == 0)
        return arr1;
    else if(arr1.size() == 0)
        return arr2;

    vector<int>::iterator pos1 = arr1.begin();
    vector<int>::iterator pos2 = arr2.begin();

    vector<int> merged;

    while(pos1 != arr1.end() || pos2 != arr2.end()) {
        if(pos1 == arr1.end())
            mergeInto(merged, pos2);
        else if(pos2 == arr2.end())
            mergeInto(merged, pos1);
        else if(*pos1 < *pos2)
            mergeInto(merged, pos1);
        else if(*pos2 < *pos1)
            mergeInto(merged, pos2);
        else if(*pos1 == *pos2) {
            mergeInto(merged, pos1);
            mergeInto(merged, pos2);
        }
    }

    return merged;
}

void mergeInto(vector<int>& merged, vector<int>::iterator& pos) {

    merged.push_back(*pos);
    pos++;

}