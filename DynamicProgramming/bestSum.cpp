#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bestSum(int targetSum, vector<int> &nums, bool sorted)
{
    if (!sorted)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        sorted = true;
    }
    if (targetSum == 0)
        return {};
    if (targetSum == -1)
        return {-1};

    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = targetSum - nums[i];
        if (remainder >= 0)
        {
            vector<int> remResult = bestSum(remainder, nums, sorted);
            if (remResult.size() == 0 || remResult[0] != -1)
            {
                remResult.push_back(nums[i]);
                return remResult;
            }
        }
    }
    return {-1};
    exit(8);
}

int main()
{
    vector<int> nums = {3, 4, 2, 7};
    vector<int> ans = bestSum(8, nums, false);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}