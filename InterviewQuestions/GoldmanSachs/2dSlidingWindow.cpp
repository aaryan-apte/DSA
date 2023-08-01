#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int maxSub(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    int ans = 0;

    for (int col = 0; col < n - k; col++)
    {
        int sum = 0;

        for (int i = 0; i < k; i++)
        {
            for (int j = col; j < col + k; j++)
            {
                sum += mat[i][j];
            }
        }
        int temp = 0;
        temp = sum;

        for (int i = k; i < n; i++)
        {
            for (int j = col; j < col + k; j++)
            {
                temp -= mat[i - k][j];
            }
            for (int j = col; j < col + k; j++)
            {
                temp += mat[i][j];
            }
            sum = max(temp, sum);
        }
        ans = max(sum, ans);
    }
    return ans;
}

int swaps(vector<int> &nums)
{
    int ones = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones += nums[i];
    }

    int window = 0;
    for (int i = 0; i < ones; i++)
    {
        window += nums[i];
    }
    int ans = window;

    for (int i = ones; i < nums.size(); i++)
    {
        window -= nums[i - ones];
        window += nums[i];
        ans = max(ans, window);
    }
    return ones - ans;
}

int main()
{
    // vector<vector<int>> mat(3);
    // mat.push_back({1, 9, 3});
    // mat.push_back({4, 2, 3});
    // mat.push_back({6, 1, 9});
    // cout << maxSub(mat, 2);
    vector<int> nums = {0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1};
    cout << swaps(nums);

    return 0;
}