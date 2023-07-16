#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> nextSmallerLeft(vector<int> &bldg)
{
    vector<int> ans(bldg.size());
    stack<pair<int, int>> st;

    st.push({bldg[0], 0});

    ans[0] = -1;

    for (int i = 1; i < bldg.size(); i++)
    {
        if (st.top().first < bldg[i])
        {
            ans[i] = st.top().second;
        }
        else
        {
            while (!st.empty() && st.top().first >= bldg[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top().second;
            }
        }
        st.push({bldg[i], i});
    }
    return ans;
}

vector<int> nextSmallerRight(vector<int> &bldg)
{
    vector<int> ans(bldg.size());

    stack<pair<int, int>> st;
    st.push({bldg[bldg.size() - 1], bldg.size() - 1});
    ans[bldg.size() - 1] = -1;

    for (int i = bldg.size() - 2; i >= 0; i--)
    {
        if (st.top().first < bldg[i])
        {
            ans[i] = st.top().second;
        }
        else
        {
            while (!st.empty() && st.top().first >= bldg[i])
                st.pop();

            if (st.empty())
            {
                ans[i] = bldg.size();
            }
            else
            {
                ans[i] = st.top().second;
            }
        }
        st.push({bldg[i], i});
    }
    return ans;
}

int findMinimumCost(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }

    stack<char> st;

    int start = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            st.push('{');
            start++;
        }
        else
        {
            if (st.empty())
            {
                st.push('}');
            }
            else if (st.top() == '{')
            {
                st.pop();
                start--;
            }
            else
            {
                st.push('}');
            }
        }
    }

    return start + st.size() / 2;
}

int main()
{
    vector<int> bldg = {1, 0, 1, 2, 2, 2, 2, 1, 0, 2};
    vector<int> ans = nextSmallerRight(bldg);
    vector<int> ans1 = nextSmallerLeft(bldg);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    for (int i : ans1)
        cout << i << " ";

    return 0;
}