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

typedef pair<int, int> p;

vector<int> frequencySort(vector<int> &nums)
{
    vector<int> ans;
    map<int, int> freq;

    for (int i : nums)
        freq[i]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mini;
    for (auto i : freq)
    {
        mini.push({i.second, i.first});
        // cout << mini.top().first << " " << mini.top().second << endl;
        // cout << i.first << " " << i.second << endl;
    }

    stack<pair<int, int>> st;

    while (mini.size() > 0)
    {
        cout << mini.top().first << " " << mini.top().second << endl;
        if (st.empty() || st.top().first == mini.top().first)
        {
            st.push(mini.top());
            cout << st.top().first << " - " << st.top().second << endl;
        }
        else
        {
            while (!st.empty())
            {
                int f = st.top().first;
                int n = st.top().second;

                for (int i = 0; i < f; i++)
                    ans.push_back(n);
                st.pop();
            }
            st.push(mini.top());
        }
        mini.pop();
    }
    while (!st.empty())
    {
        int f = st.top().first;
        int n = st.top().second;

        for (int i = 0; i < f; i++)
            ans.push_back(n);
        st.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 3, 3};
    vector<int> ans = frequencySort(nums);
    for (int i : ans)
        cout << i << " ";

    return 0;
}