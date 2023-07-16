#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void checkCelebrityStack(vector<vector<int>> &mat)
{
    stack<int> st;
    for (int i = 0; i < mat.size(); i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (mat[a][b] == 0 && mat[b][a] == 0)
        {
            continue;
        }
        if (mat[a][b] == 1)
        {
            cout << a << " not a celebrity...\n";
        }
        else
        {
            st.push(a);
        }
        if (mat[b][a] == 1)
        {
            cout << b << " not a celebrity...\n";
        }
        else
        {
            st.push(b);
        }

        if (st.size() == 1)
        {
            cout << "Celebrity found " << st.top();
        }
    }
}

vector<int> celebrity(vector<vector<int>> &mat)
{
    vector<int> ans;
    for (int i = 0; i < mat.size(); i++)
    {
        int count1 = 0, count0 = 0;
        for (int j = 0; j < mat.size(); j++)
        {
            if (mat[i][j] == 0)
            {
                count0++;
            }
        }

        for (int j = 0; j < mat.size(); j++)
        {
            if (mat[j][i] == 1)
            {
                count1++;
            }
        }

        if (count1 == mat.size() - 1 && count0 == mat.size())
        {
            cout << "Celebrity found... " << i << " is the celebrity!\n";
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    // vector<int> ans = celebrity(mat);
    // for (int i : ans)
    //     cout << i << " ";
    checkCelebrityStack(mat);
    return 0;
}