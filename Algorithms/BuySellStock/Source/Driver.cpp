#include <iostream>
#include <vector>

using namespace std;

class Investor {
    public:
        int maxProfit(vector<int>);
};

int main() {

    Investor julian;
    vector<int> stock = {10, 5, 9, 99, 56, 8, 12, 17, 1, 3};

    cout << "Stock Prices by day: \t[\t";
    for(int i = 0; i < stock.size(); i++)
        cout << stock[i] << "\t";
    cout << "]" << endl;

    cout << "Maximum Profit: \t$" << julian.maxProfit(stock) << endl;

    return 0;
}

int Investor::maxProfit(vector<int> prices) {

    int minStock = INT32_MAX;
    int maxDiff = 0;

    vector<int>::iterator i;
    for(i = prices.begin(); i != prices.end(); i++)
        if(*i < minStock)
            minStock = *i;
        else if(*i - minStock > maxDiff)
            maxDiff = *i - minStock;

    return maxDiff;
}