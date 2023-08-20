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

// typedef pair<int, int> ppi;

void deleter(stack<int> &st, int k)
{
    while (st.size() > k)
        st.pop();
}

void insertSortedStack(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }
    if (st.top() < element)
    {
        st.push(element);
        return;
    }

    int top = st.top();
    st.pop();
    insertSortedStack(st, element);
    st.push(top);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    sortStack(st);
    insertSortedStack(st, top);
}

void kthSmallestPQ(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }
    int i = 0;
    while (i < k - 1)
    {
        pq.pop();
        i++;
    }
    cout << pq.top() << endl;
}

int kthSmallest(vector<int> &nums, int k, int index)
{
    stack<int> st;
    if (st.empty())
    {
        st.push(nums[index]);
        index++;
    }

    while (index < nums.size())
    {
        if (st.size() < k)
        {
            insertSortedStack(st, nums[index]);
        }
        else
        {
            if (nums[index] < st.top())
            {
                insertSortedStack(st, nums[index]);
                deleter(st, k);
            }
        }
        index++;
    }
    return st.top();
}

int main()
{
    // stack<int> st;
    // st.push(3);
    // st.push(15);
    // st.push(7);
    // st.push(18);
    // st.push(9);
    // st.push(6);
    // insertSortedStack(st, 6);
    // sortStack(st);
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    vector<int> nums = {5, 1, 4, 3, 7, 2};
    // kthSmallestPQ(nums, 2);
    priority_queue<pair<int, int>> maxi;
    maxi.push({5, 3});
    maxi.push({5, 2});
    cout << maxi.top().second;
    return 0;
}