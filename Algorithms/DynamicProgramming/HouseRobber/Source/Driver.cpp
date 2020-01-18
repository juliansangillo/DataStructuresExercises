/**
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<vector<int>, int> MemoizeMap;

class Robber {
    private:
        MemoizeMap cache;
    public:
        int rob(vector<int>);
};

int main() {

    Robber bob;

    vector<int> houses = {5, 4, 10, 20, 35, 6, 8, 3, 12};

    cout << "Money Stolen: $" << bob.rob(houses) << endl;

    return 0;
}

int Robber::rob(vector<int> houses) {
    
    MemoizeMap::iterator m = this->cache.find(houses);
    if(m != this->cache.end())
        return m->second;

    if(houses.size() == 0)
        return 0;
    else if(houses.size() == 1)
        return houses.front();

    int profit1, profit2;
    vector<int> firstSet, secondSet;
    
    if(houses.size() > 2)
        firstSet = vector<int>(houses.begin() + 2, houses.end());
    if(houses.size() > 3)
        secondSet = vector<int>(houses.begin() + 3, houses.end());

    profit1 = houses.front() + this->rob(firstSet);
    profit2 = *next(houses.begin()) + this->rob(secondSet);

    int result = profit1 >= profit2 ? profit1 : profit2;
    this->cache.insert(make_pair(houses, result));

    return result;
}