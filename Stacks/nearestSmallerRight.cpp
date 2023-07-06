#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nearestSmallestRight(vector<int> &nums)
{
    vector<int> ans(0, nums.size());
    stack<int> st;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(nums[i]);
        }
        else
        {
            while (!st.empty() && st.top() >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
                st.push(nums[i]);
            }
            else
            {
                ans.push_back(st.top());
                st.push(nums[i]);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 0, 0, 1, 2, 4, 8};
    vector<int> ans = nearestSmallestRight(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}