#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *left;
    Node *right;

    Node(int info)
    {
        this->info = info;
        this->right = NULL;
        this->left = NULL;
    }
};

int countNodes(Node *root)
{
    int ans = 0;
    if (root == NULL)
        return 0;
    ans++;
    ans += countNodes(root->left);
    ans += countNodes(root->right);
    return ans;
}

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

int maxBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->info, max(maxBinaryTree(root->left), maxBinaryTree(root->right)));
}

int main()
{
    Node *root = buildTree(root);
    // 1 2 4 -1 78 -1 -1 7 9 -1 -1 -1 54 6 -1 -1 -1
    cout << maxBinaryTree(root);

    return 0;
}