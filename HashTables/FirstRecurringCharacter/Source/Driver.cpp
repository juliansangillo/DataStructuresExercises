#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

string firstRecur(vector<char>);

int main() {

    vector<char> chars1 = {'2', '5', '1', '2', '3', '5', '1', '2', '4'};
    vector<char> chars2 = {'2', '1', '1', '2', '3', '5', '1', '2', '4'};
    vector<char> chars3 = {'2', '3', '4', '5'};

    cout << firstRecur(chars1) << endl;
    cout << firstRecur(chars2) << endl;
    cout << firstRecur(chars3) << endl;

    return 0;
}

string firstRecur(vector<char> chars) {

    unordered_set<char> set;

    for(int i = 0; i < chars.size(); i++) {
        if(set.find(chars[i]) != set.end())
            return string(1, chars[i]);
        set.insert(chars[i]);
    }
    
    return "NULL";
}