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

vector<int> nearlySorted(int arr[], int num, int K)
{
    vector<int> ans(num, 0);

    priority_queue<int, vector<int>, greater<int>> mini;
    int index = 0;
    for (int i = 0; i <= K; i++)
    {
        mini.push(arr[i]);
    }
    ans[index] = mini.top();
    mini.pop();

    index++;

    for (int i = K + 1; i < num; i++)
    {
        mini.push(arr[i]);
        int top = mini.top();
        ans[index++] = top;
        mini.pop();
    }
    while (!mini.empty())
    {
        ans[index++] = mini.top();
        mini.pop();
    }
    return ans;
}

int main()
{

    return 0;
}