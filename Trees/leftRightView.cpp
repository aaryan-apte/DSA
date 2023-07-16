#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
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

void leftView(Node *root)
{
    queue<Node *> q;
    cout << root->info << " ";
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                cout << q.front()->info << " ";
                q.push(NULL);
            }
        }
        else
        {
            Node *curNode = q.front();
            q.pop();

            if (curNode->left != NULL)
                q.push(curNode->left);

            if (curNode->right != NULL)
                q.push(curNode->right);
        }
    }
}

void topView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                cout << q.front()->info << " ";
                q.push(NULL);
            }
        }
        else
        {
            Node *curNode = q.front();
            q.pop();
            if (q.front() == NULL)
            {
                cout << curNode->info << " ";
            }
            if (curNode->left != NULL)
                q.push(curNode->left);
            if (curNode->right != NULL)
                q.push(curNode->right);
        }
    }
}

void printLeftNodes(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    cout << root->info << " ";

    if (root->left == NULL)
        printLeftNodes(root->right);

    else
        printLeftNodes(root->left);
}

void printRightNodes(Node *root, stack<Node *> &st)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    st.push(root);

    if (root->right == NULL)
        printRightNodes(root->left, st);

    else
        printRightNodes(root->right, st);
}

void printLeafNodes(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->info << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void boundaryTraversal(Node *root)
{
    printLeftNodes(root);
    stack<Node *> st;
    printLeafNodes(root);
    printRightNodes(root, st);
    while (!st.empty())
    {
        cout << st.top()->info << " ";
        st.pop();
    }
}

void verticalOrderTraversal(int val, Node *root, map<int, vector<Node *>> &mem)
{
    // auto it = mem.find(root);
}
// void verticalOrderTraversal(Node *root, map<Node *, int> &mem)
// {
//     if (root == nullptr)
//     {
//         return;
//     }

//     mem[root->left] = mem[root] - 1;
//     mem[root->right] = mem[root] + 1;

//     if (root->left != NULL)
//         verticalOrderTraversal(root->left, mem);
//     if (root->left != NULL)
//         verticalOrderTraversal(root->right, mem);
// }

// void verticalOrderTraversalAns(Node *root)
// {
//     map<int, vector<Node*>> mem;

// }

// void verticalOrderTraversalAns(Node *root)
// {
//     map<Node *, int> mem;
//     mem[root] = 0;
//     verticalOrderTraversal(root, mem);
//     // for (auto i : mem)
//     // {
//     //     if (i.first != NULL)
//     //         cout << i.first->info << " -> " << i.second << " " << endl;
//     // }
//     vector<pair<Node *, int>> ans;
//     for (auto i : mem)
//     {
//         if (i.first != NULL)
//         {
//             ans.push_back({i.first, i.second});
//         }
//     }
//     sort(ans.begin(), ans.end(), [](pair<Node *, int> &b, pair<Node *, int> &a)
//          { return b.second > a.second; });

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i].first->info << " -> " << ans[i].second << endl;
//     }
// }

void diagonalTraversal(Node *root, map<Node *, int> &mem)
{
    if (root == NULL)
        return;

    if (root->right != NULL)
    {
        mem[root->right] = mem[root];
        diagonalTraversal(root->right, mem);
    }
    if (root->left != nullptr)
    {
        mem[root->left] = mem[root] + 1;
        diagonalTraversal(root->left, mem);
    }
}

// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

int main()
{
    Node *root = buildTree(root);
    // levelOrderTraversal(root);
    // leftView(root);
    // cout << endl;
    // topView(root);.
    // boundaryTraversal(root);
    // verticalOrderTraversalAns(root);

    map<Node *, int> mem;
    diagonalTraversal(root, mem);

    vector<pair<Node *, int>> ans;
    for (auto i : mem)
    {
        if (i.first != nullptr)
            ans.push_back({i.first, i.second});
    }

    ans.shrink_to_fit();
    sort(ans.begin(), ans.end(), [](pair<Node *, int> &a, pair<Node *, int> &b)
         { return a.second < b.second; });
    vector<int> v;
    for (auto i : ans)
    {
        v.push_back(i.first->info);
    }
    for (auto i : v)
        cout << i << " ";

    return 0;
}