#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> &nums)
{
    stack<pair<int, int>> st;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(1);
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
                ans.push_back(1);
            }
            else
            {
                ans.push_back(i - st.top().second);
            }
            st.push({nums[i], i});
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockSpan(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}