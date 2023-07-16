#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void insertAtBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(num);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int num = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, num);
}

void sortedInsert(stack<int> &st, int element)
{
    if (st.empty() || (!st.empty() && st.top() < element))
    {
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(num);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int num = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, num);
}

int main()
{
    stack<int> st;
    // st.push(4);
    // st.push(1);
    // st.push(9);
    // st.push(2);
    // insertAtBottom(st, 7);

    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    st.push(4);
    st.push(1);
    st.push(9);
    st.push(2);
    st.push(30);
    // insertAtBottom(st, 7);
    // reverseStack(st);
    cout << endl
         << endl;
    sortedInsert(st, 5);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    st.push(4);
    st.push(1);
    st.push(9);
    st.push(2);
    st.push(30);

    sortStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}