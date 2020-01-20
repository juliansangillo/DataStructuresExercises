#include <iostream>
#include <vector>

using namespace std;

class Investor {
    public:
        int maxProfit(vector<int>);
};

int main() {

    Investor julian;
    vector<int> stock = {7, 1, 5, 3, 6, 4};

    cout << "Stock Prices by day: \t[\t";
    for(int i = 0; i < stock.size(); i++)
        cout << stock[i] << "\t";
    cout << "]" << endl;

    cout << "Maximum Profit: \t$" << julian.maxProfit(stock) << endl;

    return 0;
}

int Investor::maxProfit(vector<int> prices) {



    return 0;
}