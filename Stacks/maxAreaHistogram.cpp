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

int maxAreaHistogram(vector<int> &bldg)
{
    vector<int> nearestLeft = nearestSmallerLeft(bldg);
    vector<int> nearestRight = nearestSmallerRight(bldg);
    vector<int> maxAreas;

    for (int i = 0; i < bldg.size(); i++)
    {
        // if (nearestLeft[i] == -1)
        // {
        //     if (nearestRight[i] == -1)
        //     {
        //         maxAreas.push_back(bldg[i]);
        //     }
        //     else if (nearestRight[i] == 0)
        //     {
        //         maxAreas.push_back(bldg[i] * (bldg.size()));
        //     }
        //     else
        //     {
        //         maxAreas.push_back((nearestRight[i] - i) * bldg[i]);
        //     }
        // }
        // else if (nearestRight[i] == -1)
        // {
        //     if (nearestLeft[i] == -1)
        //     {
        //         maxAreas.push_back(bldg[i]);
        //     }
        //     else if (nearestLeft[i] == 0)
        //     {
        //         maxAreas.push_back(bldg[i] * (bldg.size()));
        //     }
        //     else
        //     {
        //         maxAreas.push_back((i - nearestLeft[i]) * bldg[i]);
        //     }
        // }
        // else if (nearestLeft[i] == 0 && nearestRight[i] == 0)
        // {
        //     maxAreas.push_back((bldg.size()) * bldg[i]);
        // }
        // else if (nearestLeft[i] == 0 || nearestRight[i] == 0)
        // {
        //     maxAreas.push_back((nearestRight[i] - nearestLeft[i]) * bldg[i]);
        // }
        // else
        // {
        //     maxAreas.push_back((nearestRight[i] - nearestLeft[i] - 1) * bldg[i]);
        // }
        if (nearestLeft[i] == -1 && nearestRight[i] == -1)
        {
            maxAreas.push_back((bldg.size()) * bldg[i]);
        }
        else
        {
            maxAreas.push_back((nearestRight[i] - nearestLeft[i] - 1) * bldg[i]);
        }
    }

    int max = 0;
    for (int i : nearestLeft)
        cout << i << " ";
    cout << endl;
    for (int i : nearestRight)
        cout << i << " ";
    cout << endl;
    for (int i : maxAreas)
    {
        cout << i << " ";
        if (i > max)
            max = i;
    }
    cout << endl;
    return max;
}

int main()
{
    vector<int> bldg = {6, 2, 5, 4, 5, 1, 6};
    cout << maxAreaHistogram(bldg);

    return 0;
}