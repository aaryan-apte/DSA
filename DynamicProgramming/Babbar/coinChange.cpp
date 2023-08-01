#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int coinChange(int target, vector<int> &coins)
{
    if (target == 0)
        return 0;

    int ans = INT_MAX;

    for (int i : coins)
    {
        int rem = target - i;
        int temp = 0;

        if (rem >= 0)
        {
            temp = 1 + coinChange(rem, coins);
            if (temp < ans)
                ans = temp;
        }
    }
    if (ans == INT_MAX)
        return 0;
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 3};
    cout << coinChange(7, coins);

    return 0;
}
