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

void kSumPaths(Node *root, vector<vector<int>> &ans, vector<int> &curPath, int &count, int k)
{
    if (root == nullptr)
        return;

    curPath.push_back(root->info);

    // left
    kSumPaths(root->left, ans, curPath, count, k);

    // right
    kSumPaths(root->right, ans, curPath, count, k);

    int sum = 0;
    for (int i = curPath.size() - 1; i >= 0; i--)
    {
        sum += curPath[i];
        if (sum == k)
        {
            vector<int> temp;
            for (int j = curPath.size() - 1; j >= i; j--)
            {
                temp.push_back(curPath[j]);
            }
            temp.shrink_to_fit();
            ans.push_back(temp);
            count++;
        }
    }
    curPath.pop_back();
}

bool find_Element_kth_ancestor(Node *root, int toFind, stack<Node *> &st)
{
    if (root == nullptr)
        return false;

    st.push(root);

    if (root->info == toFind)
        return true;

    bool existsLeft = find_Element_kth_ancestor(root->left, toFind, st);
    bool existsRight = false;

    if (!existsLeft)
    {
        while (!st.empty() && st.top() != root)
            st.pop();

        existsRight = find_Element_kth_ancestor(root->right, toFind, st);

        if (!existsRight)
        {
            while (!st.empty() && st.top() != root)
                st.pop();

            st.pop();
        }
    }
    return existsLeft | existsRight;
}

void kthAncestor(Node *root, int toFind, int k)
{
    stack<Node *> st;
    find_Element_kth_ancestor(root, toFind, st);

    if (k > st.size() - 1)
        cout << "There is no possible ancestor...\n";
    else
    {
        int i = 0;
        while (!st.empty() && i < k)
        {
            st.pop();
            i++;
        }
        if (i == k)
        {
            cout << "The kth ancestor is: " << st.top()->info << endl;
        }
    }
}

// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

int main()
{
    Node *root = buildTree(root);

    kthAncestor(root, 9, 2);

    // vector<vector<int>> ans;
    // vector<int> curPath;
    // int count = 0;

    // kSumPaths(root, ans, curPath, count, 9);

    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //         cout << j << " ";

    //     cout << endl;
    // }
    // cout << count;
    return 0;
}