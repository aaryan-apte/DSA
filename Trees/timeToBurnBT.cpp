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

bool findElement(Node *root, stack<Node *> &st, int target)
{
    if (root == nullptr)
        return false;

    st.push(root);

    if (root->info == target)
        return true;

    bool ansLeft = false, ansRight = false;

    ansLeft = findElement(root->left, st, target);

    if (!ansLeft)
    {
        while (!st.empty() && st.top() != root)
            st.pop();

        ansRight = findElement(root->right, st, target);
        if (!ansRight)
        {
            while (!st.empty() && st.top() != root)
                st.pop();

            st.pop();
        }
    }
    return ansLeft | ansRight;
}

int height(Node *root)
{
    if (root = nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int timeToBurn(Node *root, int target)
{
    stack<Node *> st;

    bool exists = findElement(root, st, target);
    int downBurnHeight = height(st.top());
    int time = downBurnHeight;

    int i = st.size();

    int heightFromRoot = height(root);
    if (heightFromRoot <= downBurnHeight + i - 1)
    {
        return downBurnHeight;
    }
}

// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

int main()
{
    Node *root = buildTree(root);
    stack<Node *> st;
    cout << findElement(root, st, 8) << endl;
    cout << st.top()->info;

    return 0;
}