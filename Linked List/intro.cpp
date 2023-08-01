#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node(int info)
    {
        this->info = info;
        this->next = nullptr;
    }
};

Node *getNode(int info)
{
    Node *newNode = new Node(info);
    return newNode;
}

void buildList(Node *start)
{
    cout << "Enter data:\n";
    int info;
    cin >> info;
    if (info == -1)
        return;

    Node *newNode = getNode(info);
    start->next = newNode;
    buildList(start->next);
    // if (count == 0)
    // {
    //     cout << "Enter data (-1) for end\n";
    //     int info;
    //     cin >> info;

    //     if (info == -1)
    //         return;

    //     Node *newNode = getNode(info);
    //     start = newNode;
    //     cout << "Enter data for " << info << endl;
    // }
    // cout << "Enter data (-1) for end\n";
    // int info;
    // cin >> info;

    // if (info == -1)
    //     return;

    // Node *newNode = getNode(info);
    // start->next = newNode;
    // cout << "Enter data for " << info << endl;
    // count++;
    // buildList(start->next, count);
}

void printList(Node *root)
{
    while (root != nullptr)
    {
        cout << root->info << " ";
        root = root->next;
    }
}

void solve(Node *root, vector<int> &nums)
{
    if (root == nullptr)
        return;
    nums.push_back(root->info);
    solve(root->next, nums);
}

vector<int> getList(Node *root)
{
    if (root == nullptr)
        return {};
    vector<int> ans;
    solve(root, ans);
    return ans;
}

Node *reverseList(Node *cur, Node *p, Node *n)
{
    if (cur == nullptr)
        return nullptr;

    if (n == nullptr)
    {
        cur->next = p;
        return cur;
    }

    cur->next = p;
    p = cur;
    cur = n;
    n = n->next;
    return reverseList(cur, p, n);
}

Node *mergeLists(Node *s1, Node *s2, Node *result)
{
    Node *start = nullptr;

    if (s1 == nullptr && s2 == nullptr)
    {
        return nullptr;
    }

    if (s1 != nullptr)
    {
        result = getNode(s1->info);
    }
    start = result;
    if (s2 != nullptr)
    {
        result->next = getNode(s2->info);
        result = result->next;
    }
    result->next = mergeLists(s1->next, s2->next, result);
    return start;
}

// 41 5 6 38 2 9 8 76 78 23 4 1 60 -1

void findElement(Node *start, int key)
{
    if (start == nullptr)
        return;

    if (start->info == key)
    {
        cout << key << " element found\n";
        return;
    }
    findElement(start->next, key);
}

int main()
{
    Node *root = getNode(3);
    buildList(root);

    vector<int> ans = getList(root);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    // findElement(root, 1);
    root = reverseList(root, nullptr, root->next);
    ans = getList(root);
    for (int i : ans)
        cout << i << " ";

    Node *s1, *s2;
    buildList(s1);
    buildList(s2);

    return 0;
}