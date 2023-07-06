#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerLeft(vector<int> &nums)
{
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < nums.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(nums[i]);
        }
        else
        {
            while (!st.empty() && st.top() >= nums[i])
                st.pop();

            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(nums[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 4, 2, 1, 9, 8, 6, 9};
    vector<int> ans = nearestSmallerLeft(nums);

    for (int i : ans)
        cout << i << " ";

    return 0;
}