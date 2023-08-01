#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <deque>
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

bool checkParentChild(Node *root, int child, int parent)
{
    if (root == nullptr)
        return false;

    if (root->info == parent)
    {
        if (root->left != nullptr && root->left->info == child)
        {
            return true;
        }
        if (root->right != nullptr && root->right->info == child)
        {
            return true;
        }
    }
    if (root->info == child)
    {
        if (root->left != nullptr && root->left->info == parent)
        {
            return true;
        }
        if (root->right != nullptr && root->right->info == parent)
        {
            return true;
        }
    }

    return checkParentChild(root->left, child, parent) | checkParentChild(root->right, child, parent);
}

// 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

int longestPath(vector<vector<int>> &graph, int destCol, int destRow, int row, int col, map<pair<int, int>, bool> &visited)
{
    if (row == destRow && col == destCol)
    {
        return 0;
    }

    if (col >= graph[0].size() || row >= graph.size() || row < 0 || col < 0 || graph[row][col] == 0)
    {
        return -1;
    }

    if (visited[{row, col}])
    {
        return -1; // Already visited this cell in the current path, so we avoid cycles.
    }

    visited[{row, col}] = true; // Marking the cell as visited before recursive exploration.

    int ans = 0;
    ans = max(ans, 1 + longestPath(graph, destCol, destRow, row - 1, col, visited));
    ans = max(ans, 1 + longestPath(graph, destCol, destRow, row + 1, col, visited));
    ans = max(ans, 1 + longestPath(graph, destCol, destRow, row, col - 1, visited));
    ans = max(ans, 1 + longestPath(graph, destCol, destRow, row, col + 1, visited));

    // visited[{row, col}] = false; // Marking the cell as unvisited after recursive exploration.

    return ans;
    // if (row == destRow && col == destCol)
    // {
    //     return 0;
    // }

    // if (col >= graph[0].size() || row >= graph.size() || row < 0 || col < 0)
    //     return -1;

    // int ans = 0;
    // if (!visited[{row - 1, col}] && row > 0 && graph[row - 1][col] == 1)
    // {
    //     visited[{row - 1, col}] = true;
    //     ans = max(ans, 1 + longestPath(graph, destCol, destRow, row - 1, col, visited));
    // }
    // if (!visited[{row + 1, col}] && row < graph.size() - 1 && graph[row + 1][col] == 1)
    // {
    //     visited[{row + 1, col}] = true;
    //     ans = max(ans, 1 + longestPath(graph, destCol, destRow, row + 1, col, visited));
    // }
    // if (!visited[{row, col - 1}] && col > 0 && graph[row][col - 1] == 1)
    // {
    //     visited[{row, col - 1}] = true;
    //     ans = max(ans, 1 + longestPath(graph, destCol, destRow, row, col - 1, visited));
    // }
    // if (!visited[{row, col + 1}] && col < graph[0].size() && graph[row][col + 1] == 1)
    // {
    //     visited[{row, col + 1}] = true;
    //     ans = max(ans, 1 + longestPath(graph, destCol, destRow, row, col + 1, visited));
    // }
    // return ans;
}

vector<pair<int, int>> findPairs(vector<int> &bikes, vector<int> &riders, int prod)
{
    vector<pair<int, int>> ans;

    sort(bikes.begin(), bikes.end());
    sort(riders.begin(), riders.end());
    map<int, bool> taken;

    for (int i = 0; i < riders.size(); i++)
    {
        for (int j = 0; j < riders.size(); j++)
        {
            if (!taken[j] && riders[i] * bikes[j] >= prod)
            {
                ans.push_back({riders[i], bikes[j]});
                taken[j] = true;
                break;
            }
        }
    }
    return ans;
}

void largestSubarray(vector<int> &nums)
{
    int i = 0, j = 0;
    int maxSize = 0;
    int low = 0, high = 0;

    while (j < nums.size())
    {
    }
}

int main()
{
    // Node *root = buildTree(root);
    // cout << checkParentChild(root, 2, 8);

    // vector<vector<int>> nums;
    // nums.push_back({0, 1, 1, 1, 0});
    // nums.push_back({1, 1, 0, 1, 0});
    // nums.push_back({0, 1, 0, 1, 1});
    // nums.push_back({0, 1, 1, 1, 1});
    // map<pair<int, int>, bool> visited;
    // cout << longestPath(nums, 4, 3, 1, 0, visited);
    vector<int> bikes = {3, 3, 6, 5, 8};
    vector<int> riders = {2, 3, 1, 4, 6};
    vector<pair<int, int>> ans = findPairs(bikes, riders, 15);
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
    return 0;
}