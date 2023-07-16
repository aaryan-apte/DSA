#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
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

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

void sumHeight(Node *root, stack<Node *> &st)
{
    if (root == nullptr)
        return;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
    {
        st.push(root->left);
        sumHeight(root->left, st);
    }
    // else if(leftHeight == rightHeight)
    // {

    // }
    else
    {
        st.push(root->right);
        sumHeight(root->right, st);
    }
}

pair<Node *, int> sumHeightPair(Node *root, pair<Node *, int> &p)
{
    if (root == nullptr)
        return p;

    pair<Node *, int> curPair = make_pair(root, p.second + root->info), l = make_pair(nullptr, 0), r = make_pair(nullptr, 0);

    l = sumHeightPair(root->left, curPair);
    r = sumHeightPair(root->right, curPair);

    curPair.second += max(l.second, r.second);

    // if (root->left != nullptr)
    // {
    //     // l = make_pair(root->left, p.second + root->left->info); // p.second + root->left->info;
    //     // l.second += sumHeightPair(root->left, l).second;
    // }
    // if (root->right != nullptr)
    // {
    //     // r = make_pair(root->right, p.second + root->right->info); // p.second + root->left->info;
    //     // r.second += sumHeightPair(root->right, r).second;
    // }

    // if (l.first != nullptr && r.first != nullptr)
    // {
    //     if (l.second > r.second)
    //     {
    //         cout << "Root = " << root->info << " -> " << l.second << " " << endl;
    //         return l;
    //     }
    // }
    // cout << "Root = " << root->info << " -> " << r.second << " " << endl;
    return curPair;
}

int main()
{
    // 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Node *root = buildTree(root);

        // pair<Node *, int> p = make_pair(nullptr, 0);
    // p = sumHeightPair(root, p);
    // cout << p.second;
    // pair<Node *, int> sum = sumHeightPair(root, p);
    // cout << sum.second;

    // cout << height(root)
    //      << endl
    //      << endl;

    // stack<Node *> st;
    // st.push(root);
    // int sum = 0;

    // sumHeight(root, st);
    // // cout << st.empty();

    // while (!st.empty())
    // {
    //     if (st.top() != nullptr)
    //     {
    //         sum += st.top()->info;
    //     }
    //     st.pop();
    // }
    // cout << "Sum: " << sum << endl;

    return 0;
}