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

int findElement(vector<int> &inOrder, int n)
{
    for (int i = 0; i < inOrder.size(); i++)
    {
        if (inOrder[i] == n)
            return i;
    }
    return -1;
}

Node *fromInorderPreorder(vector<int> &inOrder, vector<int> &preOrder, int startIndex, int endIndex, int &preIndex)
{
    if (preIndex >= inOrder.size() || startIndex > endIndex)
        return nullptr;

    int element = preOrder[preIndex++];

    Node *root = new Node(element);
    cout << root->info << " ";
    int positionInorder = findElement(inOrder, element);

    // if (positionInorder == startIndex)
    //     root->left = nullptr;

    // else
    root->left = fromInorderPreorder(inOrder, preOrder, startIndex, positionInorder - 1, preIndex);

    // if (positionInorder == endIndex)
    //     root->right = nullptr;

    // else
    root->right = fromInorderPreorder(inOrder, preOrder, positionInorder + 1, endIndex, preIndex);

    return root;
}

// void postOrder(Node *root)
// {
//     if (root == nullptr)
//         return;

//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->info << " ";
// }

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        cout << q.front()->info << " ";
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

Node *treeFromPostorderInorder(vector<int> &inOrder, vector<int> &postOrder, int startIndex, int endIndex, int &postIndex)
{
    if (postIndex < 0 || startIndex > endIndex)
        return nullptr;

    int element = postOrder[postIndex--];
    Node *root = new Node(element);

    int inPos = findElement(inOrder, element);

    root->right = treeFromPostorderInorder(inOrder, postOrder, inPos + 1, endIndex, postIndex);
    root->left = treeFromPostorderInorder(inOrder, postOrder, startIndex, inPos - 1, postIndex);

    return root;
}

int main()
{
    Node *root;
    vector<int> preOrder = {1, 2, 4, 5, 7, 3, 6, 8};
    vector<int> inOrder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postOrder = {8, 4, 5, 2, 6, 7, 3, 1};

    // int preIndex = 0;
    int postIndex = postOrder.size() - 1;

    // root = fromInorderPreorder(inOrder, preOrder, 0, preOrder.size() - 1, preIndex);
    root = treeFromPostorderInorder(inOrder, postOrder, 0, postOrder.size() - 1, postIndex);
    cout << endl;

    levelOrderTraversal(root);
    cout << endl;
    // postOrder(root);

    return 0;
}