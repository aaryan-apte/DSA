#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> left(vector<int> &nums)
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
            while (!st.empty() && st.top() <= nums[i])
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
    vector<int> nums = {4, 2, 3, 4};
    vector<int> ans = left(nums);

    for (int i : ans)
        cout << i << " ";

    return 0;
}