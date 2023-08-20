#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> nextGreater(vector<int> &nums)
{
    stack<pair<int, int>> st;

    vector<int> ans(nums.size(), -1);
    st.push({nums.back(), nums.size() - 1});

    for (int i = nums.size() - 2; i >= 0; i++)
    {
        if (st.empty())
            ans[i] = -1;

        else if (st.top().first > nums[i])
            ans[i] = st.top().first;

        else
        {
            while (!st.empty() && st.top().first < nums[i])
                st.pop();

            if (st.empty())
                ans[i] = -1;
        }
        st.push({nums[i], i});
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 4, 9, 3, 5, 8, 7, 9};
    vector<int> ans = nextGreater(nums);
    for (int i : nums)
        cout << i << " ";

    cout << endl;

    for (int i : ans)
        cout << i << " ";

    return 0;
}