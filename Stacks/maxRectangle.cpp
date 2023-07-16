#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
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
    vector<int> ans;
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

int maxRectangle(vector<vector<int>> &mat)
{
    int maxArea = 0;
    for (int i = mat.size() - 1; i >= 0; i--)
    {
        vector<int> bldg(mat.size(), 0);

        for (int j = 0; j < mat.size(); j++)
        {
            int k = i;
            while (k >= 0)
            {
                if (mat[k][j] == 1)
                {
                    k--;
                }
                else
                {
                    break;
                }
            }
            bldg[j] = i - k;
        }

        vector<int> nextSmallerRight = nearestSmallerRight(bldg);
        vector<int> nextSmallerLeft = nearestSmallerLeft(bldg);

        for (int j = 0; j < bldg.size(); j++)
        {
            int area = (nextSmallerRight[j] - nextSmallerLeft[j] - 1) * bldg[j];
            if (area > maxArea)
                maxArea = area;
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout << maxRectangle(mat);

    return 0;
}