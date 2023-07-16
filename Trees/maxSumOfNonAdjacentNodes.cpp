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

pair<int, int> maxSum(Node *root)
{
    if (root == nullptr)
        return {0, 0};

    pair<int, int> left = maxSum(root->left);

    pair<int, int> right = maxSum(root->right);

    pair<int, int> ans;

    int takeCurNode = root->info + left.second + right.second;
    int dontTakeCurNode = left.first + right.first;

    ans = {takeCurNode, dontTakeCurNode};
    cout << root->info << " is: {" << ans.first << ", " << ans.second << "}" << endl;

    return ans;
}

int main()
{
    Node *root = buildTree(root);
    pair<int, int> ans = maxSum(root);
    cout << max(ans.first, ans.second);

    return 0;
}