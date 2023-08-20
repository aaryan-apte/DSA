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

    Node(int info)
    {
        this->info = info;
        this->right = nullptr;
        this->left = nullptr;
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

int numberOfNodes(Node *root)
{
    if (root == nullptr)
        return 0;

    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

vector<int> nextGreater(vector<int> &nums)
{
    stack<pair<int, int>> st;

    vector<int> ans(nums.size(), -1);
    st.push({nums.back(), nums.size() - 1});

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (st.empty())
            ans[i] = -1;

        else if (st.top().first > nums[i])
            ans[i] = st.top().first;

        else
        {
            while (!st.empty() && st.top().first < nums[i])
                st.pop();

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top().first;
        }
        st.push({nums[i], i});
    }
    return ans;
}

void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *node = q.front();

        if (node == nullptr)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
                q.push(nullptr);

            continue;
        }
        cout << node->info << " ";

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
        q.pop();
    }
}

int maxBT(Node *root)
{
    if (root == nullptr)
        return 0;

    return max(root->info, max(maxBT(root->right), maxBT(root->left)));
}

void leftView(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;

    q.push(root);
    cout << root->info << " ";
    q.push(nullptr);

    while (!q.empty())
    {
        Node *node = q.front();

        if (node == nullptr)
        {
            // cout << endl;
            q.pop();

            if (!q.empty())
            {
                cout << q.front()->info << " ";
                q.push(nullptr);
            }

            continue;
        }
        // cout << node->info << " ";

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
        q.pop();
    }
}

void rightView(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;

    q.push(root);
    cout << root->info << " ";
    q.push(nullptr);

    while (!q.empty())
    {
        Node *node = q.front();

        if (node == nullptr)
        {
            // cout << endl;
            q.pop();

            if (!q.empty())
            {
                cout << q.front()->info << " ";
                q.push(nullptr);
            }

            continue;
        }
        // cout << node->info << " ";

        if (node->right != nullptr)
            q.push(node->right);

        if (node->left != nullptr)
            q.push(node->left);
        q.pop();
    }
}

void topView(Node *root, map<int, int> &mem, int curr)
{
    if (root == nullptr)
        return;

    mem[curr] = root->info;

    if (!mem.count(curr - 1))
    {
        topView(root->left, mem, curr - 1);
    }
    if (!mem.count(curr + 1))
    {
        topView(root->right, mem, curr + 1);
    }
}

Node *treeFromLevelOrderTrav(queue<int> &out)
{
    Node *root = new Node(out.front());

    queue<Node *> in;
    out.pop();

    root->left = new Node(out.front());
    in.push(root->left);
    out.pop();

    root->right = new Node(out.front());
    in.push(root->right);
    out.pop();

    while (!out.empty())
    {
        Node *node = in.front();
        node->left = new Node(out.front());
        in.push(node->left);
        out.pop();

        if (!out.empty())
        {
            node->right = new Node(out.front());
            in.push(node->right);
            out.pop();
        }
        in.pop();
    }
    return root;
}

int diameter(Node *root)
{
    if (root == nullptr)
        return 0;

    int h = height(root->left) + height(root->right);
    return max(h, max(diameter(root->left), diameter(root->right)));
}

bool checkBalanced(Node *root)
{
    if (root == nullptr)
        return true;

    if (abs(height(root->left) - height(root->right)) > 1)
    {
        return false;
    }
    return checkBalanced(root->left) & checkBalanced(root->right);
}

bool checkIdentical(Node *p, Node *q)
{
    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr ^ q == nullptr)
        return false;

    else if (p != nullptr && q != nullptr)
    {
        if (p->info != q->info)
            return false;
        // labs(-2 + -4);
    }
    return checkIdentical(p->left, q->left) & checkIdentical(p->right, q->right);
}

void printLeaves(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        cout << root->info << " ";

    printLeaves(root->left);
    printLeaves(root->right);
}

void printLeft(Node *root)
{
    if (root == nullptr)
        return;

    if (root->left != nullptr && root->right != nullptr)
        cout << root->info << " ";
    if (root->left != nullptr)
        printLeft(root->left);
    else
        printLeft(root->right);
}

void printRight(Node *root, stack<int> &st)
{
    if (root == nullptr)
        return;

    if (root->left != nullptr && root->right != nullptr)
        st.push(root->info);

    if (root->right != nullptr)
        printLeft(root->right);

    else
        printLeft(root->left);
}

void boundaryTraversal(Node *root)
{
    stack<int> st;
    printLeft(root);
    printLeaves(root);
    printRight(root, st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

void diagonalTraversal(Node *root, map<int, list<int>> &mem, int curr)
{
    if (root == nullptr)
        return;

    mem[curr].push_back(root->info);
    diagonalTraversal(root->right, mem, curr);
    diagonalTraversal(root->left, mem, curr + 1);
}

void maxDepthWithPath(Node *root, vector<Node *> &v)
{
    if (root == nullptr)
        return;

    v.push_back(root);

    int hLeft = height(root->left);
    int hRight = height(root->right);

    if (hLeft > hRight)
        maxDepthWithPath(root->left, v);
    else
        maxDepthWithPath(root->right, v);
}

bool searchElementPath(Node *root, stack<Node *> &st, int key)
{
    if (root == nullptr)
        return false;

    if (root->info == key)
    {
        st.push(root);
        return true;
    }
    st.push(root);
    bool left = searchElementPath(root->left, st, key);
    bool right = false;
    if (!left)
    {
        while (!st.empty() && st.top() != root)
        {
            st.pop();
        }
        right = searchElementPath(root->right, st, key);
        if (!right)
        {
            while (!st.empty() && st.top() != root)
            {
                st.pop();
            }

            st.pop();
        }
    }
    return left | right;
}

void maxSumOfNonAdjacent(Node *root, map<Node *, pair<int, int>> &mem)
{
    if (root == nullptr)
        return;

    maxSumOfNonAdjacent(root->left, mem);
    maxSumOfNonAdjacent(root->right, mem);

    pair<int, int> p;
    if (root->right == nullptr && root->left == nullptr)
    {
        p.first = root->info;
        p.second = 0;
    }
    else
    {
        p.first = root->info + mem[root->right].second + mem[root->left].second;
        p.second = mem[root->right].first + mem[root->left].first;
    }
    mem[root] = p;
}

Node *treeFromInorderPreorder(vector<int> &in, vector<int> &pre, int start, int end, int &index)
{
    if (index > end)
        return nullptr;

    Node *newNode = new Node(pre[index]);
    int i = start;
    for (; i <= end; i++)
    {
        if (in[i] == pre[index])
            break;
    }
    index++;
    if (i == start)
        newNode->right = treeFromInorderPreorder(in, pre, start + 1, end, index);

    else if (i == end)
        newNode->left = treeFromInorderPreorder(in, pre, start, end - 1, index);
    else
    {
        newNode->left = treeFromInorderPreorder(in, pre, start, i - 1, index);
        newNode->right = treeFromInorderPreorder(in, pre, i + 1, end, index);
    }
    return newNode;
}

int main()
{
    // NEAREST GREATER ELEMENT ON RIGHT
    // vector<int> nums = {1, 4, 9, 3, 5, 8, 7, 9};
    // vector<int> ans = nextGreater(nums);
    // for (int i : nums)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : ans)
    //     cout << i << " ";
    // Node *root = buildTree(root);

    // LEVEL ORDER TRAVERSAL
    // levelOrderTraversal(root);

    // NUMBER OF NODES:
    // cout << numberOfNodes(root);

    // HEIGHT:
    // cout << height(root);

    // MAXBT:;
    // cout << maxBT(root);

    // LEFT VIEW:
    // leftView(root);
    // cout << endl;
    // RIGHT VIEW:
    // rightView(root);

    // TOP VIEW:
    // map<int, int> mem;
    // topView(root, mem, 0);
    // list<int> l;
    // for (auto i : mem)
    //     l.push_back(i.second);
    // for (int i : l)
    // cout << i << " ";
    // cout << i.first << " => " << i.second << endl;
    // queue<int> out;
    // out.push(1);
    // out.push(2);
    // out.push(3);
    // out.push(4);
    // out.push(5);
    // out.push(6);
    // out.push(7);
    // out.push(8);
    // out.push(9);
    // Node *root = treeFromLevelOrderTrav(out);

    // while (!out.empty())
    //     out.pop();

    // out.push(1);
    // out.push(2);
    // out.push(3);
    // out.push(4);
    // out.push(5);
    // out.push(6);
    // out.push(7);
    // out.push(90);
    // out.push(9);
    // Node *p = treeFromLevelOrderTrav(out);
    // levelOrderTraversal(root);
    // cout << diameter(root);
    // cout << height(root);
    // cout << checkBalanced(root);
    // cout << checkIdentical(root, p);

    // boundaryTraversal(root);
    // map<int, list<int>> mem;
    // diagonalTraversal(root, mem, 1);
    // for (auto i : mem)
    // {
    //     cout << i.first << " => ";
    //     for (int j : i.second)
    //         cout << j << " ";
    //     cout << endl;
    // }

    // vector<Node *> path;
    // maxDepthWithPath(root, path);
    // for (auto i : path)
    //     cout << i->info << " ";

    // stack<Node *> st;
    // searchElementPath(root, st, 9);
    // while (!st.empty())
    // {
    //     cout << st.top()->info << " ";
    //     st.pop();
    // }
    // map<Node *, pair<int, int>> mem;
    // maxSumOfNonAdjacent(root, mem);
    // cout << max(mem[root].first, mem[root].second);

    vector<int> in = {4, 2, 7, 5, 1, 8, 6, 3};
    vector<int> pre = {1, 2, 4, 5, 7, 3, 6, 8};
    int index = 0;
    Node *root = treeFromInorderPreorder(in, pre, 0, in.size() - 1, index);
    levelOrderTraversal(root);
    return 0;
}
