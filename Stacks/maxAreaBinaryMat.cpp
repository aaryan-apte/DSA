#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nearestSmallerLeft(vector<int> &nums)
{
    vector<int> ans;
    stack<pair<int, int>> st;

    ans.push_back(-1);
    st.push({nums[0], 0});

    for (int i = 1; i < nums.size(); i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push({nums[i], i});
        }
        else
        {
            while (!st.empty() && st.top().first >= nums[i])
                st.pop();

            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top().second);
            st.push({nums[i], i});
        }
    }
    return ans;
}

vector<int> nearestSmallerRight(vector<int> &nums)
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
            while (!st.empty() && st.top().first >= nums[i])
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

int maxAreaBinaryMatrix(vector<vector<int>> &mat)
{
    int maxArea = 0;
    for (int i = mat.size() - 1; i >= 0; i--)
    {
        vector<int> bldg(mat.size(), 0);
        for (int j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] == 0)
                continue;

            int k = i;
            while (k >= 0 && mat[k][j] == 1)
                k--;

            bldg[j] = i - k;
        }

        vector<int> nsr = nearestSmallerRight(bldg);
        vector<int> nsl = nearestSmallerLeft(bldg);

        int area = 0;
        vector<int> ans;

        for (int i = 0; i < bldg.size(); i++)
        {
            if (nsr[i] == -1 && nsl[i] == -1)
            {
                ans.push_back(bldg.size() * bldg[i]);
            }
            else
            {
                ans.push_back((nsr[i] - nsl[i] - 1) * bldg[i]);
            }
            if (ans.back() > area)
                area = ans.back();
        }
        if (maxArea < area)
            maxArea = area;

        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout << maxAreaBinaryMatrix(mat);

    return 0;
}