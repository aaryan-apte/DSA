#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> howSum(int targetSum, int nums[], int n, map<int, vector<int>> mem)
{
    auto it = mem.find(targetSum);
    if (it != mem.end())
    {
        return it->second;
    }

    if (targetSum == 0)
        return {};

    else if (targetSum < 0)
        return {-1};

    for (int i = 0; i < n; i++)
    {
        int remainder = targetSum - nums[i];
        vector<int> remainderResult = howSum(remainder, nums, n, mem);
        if (remainderResult.size() == 0 || remainderResult[0] != -1)
        {
            remainderResult.push_back(nums[i]);
            mem[nums[i]] = remainderResult;
            return mem[nums[i]];
        }
    }
    return {-1};
}

int main()
{
    int nums[4] = {10, 2, 8, 4};
    map<int, vector<int>> mem;
    vector<int> ans = howSum(136, nums, 4, mem);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}