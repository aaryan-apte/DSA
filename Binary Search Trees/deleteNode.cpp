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
    int info;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->info = info;
        this->right = nullptr;
        this->left = nullptr;
    }
};

void findSuccessor(Node *root)
{
    if (root == nullptr)
        return;
    while (root->left != nullptr)
        root = root->left;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root;

    // 0 children chi case::

    if (root->info == key)
    {
        if (root->left == nullptr && root->right == nullptr)
            delete root;

        else if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = root;
            findSuccessor(root->right);
            temp->info = root->info;
            root->right = deleteNode(root, root->info);
            return temp;
        }
    }
    else if (root->info > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
}

int main()
{

    return 0;
}