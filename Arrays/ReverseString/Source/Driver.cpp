#include <iostream>

using namespace std;

string reverse(string);

int main()
{

    cout << reverse("Hello World!") << endl;
    cout << reverse("My name is") << endl;
    cout << reverse("Julian Sangillo") << endl;
    cout << reverse("M") << endl;
    cout << reverse("") << endl;

    return 0;
}

string reverse(string str) {

    string reversedStr = "";

    for(int i = str.length() - 1; i >= 0; i--)
        reversedStr += str[i];

    return reversedStr;
}