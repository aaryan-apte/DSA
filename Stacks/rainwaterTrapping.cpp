#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nearestGreaterEqualRight(vector<int> &nums)
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

int rainwaterTrapping(vector<int> &bldg)
{
    // vector<int> ans(bldg.size(), 0);
    vector<int> nger;
    // ngel = nearestGreaterEqualLeft(bldg);
    nger = nearestGreaterEqualRight(bldg);
    cout << "Nger: ";
    for (int i : nger)
        cout << i << " ";
    cout << endl;
    int ans = 0;
    for (int i = 0; i < bldg.size();)
    {
        if (nger[i] == -1) // bldg.size())
        {
            int source = i;
            i++;
            int maxIndex = i, maxNumber = 0;
            while (i < bldg.size())
            {
                if (bldg[i] > maxNumber)
                {
                    maxIndex = i;
                    maxNumber = bldg[i];
                }
                i++;
            }
            if (maxIndex == source + 1)
            {
                break;
            }

            int area1 = (maxIndex - source - 1) * maxNumber;
            int j = i + 1;
            while (j < maxIndex)
            {
                area1 -= bldg[j];
                j++;
            }
            // ans += area1;
            i = maxIndex;
            cout << area1 << " ";
        }
        else
        {
            int area1 = (nger[i] - i + 1) * bldg[i];
            int dest = nger[i];
            while (i != dest)
            {
                i++;
                area1 -= bldg[i];
            }
            area1 += bldg[i];
            ans += area1;
            cout << area1 << " ";
        }
    }
    cout << endl;
    return ans;
}

int main()
{
    vector<int> bldg = {1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainwaterTrapping(bldg);
    // vector<int> ans1, ans2;
    // ans1 = nearestGreaterLeft(nums);
    // ans2 = nearestGreaterRight(nums);
    // for (int i : ans1)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : ans2)
    //     cout << i << " ";

    return 0;
}
