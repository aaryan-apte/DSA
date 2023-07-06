#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nearestGreaterEqualRight(vector<int> &nums)
{
    vector<int> ans(0, 9);
    stack<pair<int, int>> st;

    ans.push_back(nums.size());
    st.push({nums[nums.size() - 1], nums.size() - 1});

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push({nums[i], i});
        }
        else
        {
            while (!st.empty() && st.top().first < nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
                st.push({nums[i], i});
            }
            else
            {
                ans.push_back(st.top().second);
                st.push({nums[i], i});
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nearestGreaterEqualLeft(vector<int> &nums)
{
    vector<int> ans(0, nums.size());
    stack<pair<int, int>> st;

    ans.push_back(nums.size());
    st.push({nums[nums.size() - 1], nums.size() - 1});

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push({nums[i], i});
        }
        else
        {
            while (!st.empty() && st.top().first < nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
                st.push({nums[i], i});
            }
            else
            {
                ans.push_back(st.top().second);
                st.push({nums[i], i});
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}