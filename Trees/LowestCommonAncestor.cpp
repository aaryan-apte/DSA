#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <deque>
#include "tree.cpp"
using namespace std;

Node *buildTree(Node *root)
{
    cout << "Enter data for node: (-1) if you don't want the node\n";
    int info;
    cin >> info;
    if (info == -1)
        return NULL;

    root = new Node(info);

    cout << "Enter data for left of :" << info << "\n";
    root->left = buildTree(root->left);

    cout << "Enter data for right of :" << info << "\n";
    root->right = buildTree(root->right);

    return root;
}

bool findElement(Node *root, int n, stack<Node *> &st)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->info == n)
    {
        st.push(root);
        return true;
    }
    st.push(root);
    bool ans1 = findElement(root->left, n, st);
    bool ans2;
    if (!ans1)
    {
        while (!st.empty() && st.top() != root)
            st.pop();

        ans2 = findElement(root->right, n, st);
        if (!ans2)
        {
            while (!st.empty() && st.top() != root)
                st.pop();

            st.pop();
        }
    }

    return ans1 | ans2;
}

void lowestCommonAncestor(Node *root, int n1, int n2)
{
    // stack<Node *> s1, s2;
    // if (findElement(root, n1, s1) & findElement(root, n2, s2))
    // {
    //     cout << "Elements found...\n";

    //     cout << "s1: ";
    //     deque<int> dq1, dq2;
    //     while (!s1.empty())
    //     {
    //         if (s1.top() != nullptr)
    //         {
    //             cout << s1.top()->info << " ";
    //             dq1.push_front(s1.top()->info);
    //         }
    //         s1.pop();
    //     }

    //     cout << endl;
    //     cout << "s2: ";
    //     while (!s2.empty())
    //     {
    //         if (s2.top() != nullptr)
    //         {
    //             cout << s2.top()->info << " ";
    //             dq1.push_front(s2.top()->info);
    //         }
    //         s2.pop();
    //     }
    //     cout << endl;
    //     int ans;
    //     ans = dq1.back();
    //     while (!dq1.empty() && !dq2.empty())
    //     {
    //         if (dq1.back() == dq2.back())
    //         {
    //             ans = dq1.back();
    //             cout << "Ans: " << ans << endl;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //         dq1.pop_back();
    //         dq2.pop_back();
    //     }

    //     // vector<int> v1, v2;
    //     // // deque<int> dq1, dq2;
    //     // while (!s1.empty())
    //     // {
    //     //     if (s1.top() != nullptr)
    //     //         v1.push_back(s1.top()->info);
    //     //     s1.pop();
    //     // }
    //     // while (!s2.empty())
    //     // {
    //     //     if (s2.top() != nullptr)
    //     //         v2.push_back(s2.top()->info);
    //     //     s2.pop();
    //     // }
    //     // int ans = root->info;
    //     // while (v1.back() == v2.back())
    //     // {
    //     //     ans = v1.back();
    //     //     cout << "Ans: " << ans << "\n";
    //     //     v1.pop_back();
    //     // }
    //     cout << ans << endl;
    // }
    stack<Node *> s1, s2;
    if (findElement(root, n1, s1) & findElement(root, n2, s2))
    {
        cout << "Elements found...\n";

        cout << "s1: ";
        deque<int> dq1, dq2;
        while (!s1.empty())
        {
            cout << s1.top()->info << " ";
            dq1.push_front(s1.top()->info);
            s1.pop();
        }

        cout << endl;
        cout << "s2: ";
        while (!s2.empty())
        {
            cout << s2.top()->info << " ";
            dq2.push_front(s2.top()->info);
            s2.pop();
        }
        cout << endl;
        int ans;
        while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front())
        {
            ans = dq1.front();
            // cout << "Ans: " << ans << endl;
            dq1.pop_front();
            dq2.pop_front();
        }
        cout << "Ans: " << ans;
    }
}

int main()
{
    Node *root = buildTree(root);
    stack<Node *> st;
    // cout << findElement(root, 9, st);
    // cout << endl;
    // while (!st.empty())
    // {
    //     if (st.top() != nullptr)
    //         cout << st.top()->info << " ";
    //     st.pop();
    // }

    lowestCommonAncestor(root, 4, 5);

    return 0;
}

// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1