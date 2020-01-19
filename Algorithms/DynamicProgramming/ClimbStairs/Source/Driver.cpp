/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <iostream>
#include <map>

using namespace std;

typedef map<int, unsigned long> MemoizeMap;

class Climber {
    private:
        MemoizeMap cache;
    public:
        Climber() {
            
            cache.insert(make_pair(0, 0));
            cache.insert(make_pair(1, 1));
            cache.insert(make_pair(2, 2));
            cache.insert(make_pair(3, 3));

        }

        unsigned long climbStairs(int);
};

int main() {

    Climber mike;

    int stairs = 100;

    cout << "Number of stairs: " << stairs << endl;
    cout << "Number of ways to climb: " << mike.climbStairs(stairs) << endl;

    return 0;
}

unsigned long Climber::climbStairs(int n) {

    MemoizeMap::iterator s = cache.find(n);
    if(s != cache.end())
        return s->second;

    unsigned long result = this->climbStairs(n - 1) + this->climbStairs(n - 2);
    cache.insert(make_pair(n, result));

    return result;
}