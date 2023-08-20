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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

void insertIntoBST(Node *root, int val)
{
    if (root == nullptr)
    {
        Node *newNode = new Node(val);
        root = newNode;
        return;
    }
    if (root->data < val && root->right == nullptr)
    {
        Node *newNode = new Node(val);
        root->right = newNode;
        return;
    }
    else if (root->data > val && root->left == nullptr)
    {
        Node *newNode = new Node(val);
        root->left = newNode;
        return;
    }
    else if (root->data > val)
    {
        insertIntoBST(root->left, val);
    }
    else
        insertIntoBST(root->right, val);
}

void getInput(Node *root)
{
    Node *temp = root;
    while (1)
    {
        cout << "Enter data. (-1) to exit\n";
        int data;
        cin >> data;

        if (data == -1)
            return;

        insertIntoBST(root, data);
    }
    root = temp;
}

// int inorderSuccessor(Node *root, int key)
// {
//     if (root == nullptr)
//         return 0;

//     if (root->data == key && root->right != nullptr)
//     {
//         inorderSuccessor(root->right, key);
//     }
// }

// 6 5 8 7 98 21 45 78 -1

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    getInput(root);
    inorder(root);

    return 0;
}