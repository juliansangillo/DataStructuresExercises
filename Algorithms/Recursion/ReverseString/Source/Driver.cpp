#include<iostream>
#include<string> 

using namespace std;

string reverse(string);

int main() {

    string str = "Julian Sangillo";

    cout << "String: " << str << endl;
    cout << "Reverse: " << reverse(str) << endl;

    return 0;
}

string reverse(string str) {

    if(str.size() <= 1)
        return str;

    return reverse(str.substr(1)) + str[0];
}