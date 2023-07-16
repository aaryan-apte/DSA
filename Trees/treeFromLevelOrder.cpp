#include <iostream>
#include <queue>
#include <map>
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

void treeFromLevelOrder(Node *root, vector<int> &lot)
{
    int i = 0;
    queue<Node *> q;
    q.push(root);

    while (i < lot.size() - 1 && !q.empty())
    {
        Node *curNode = q.front();

        Node *leftNode = new Node(lot[i + 1]);
        curNode->left = leftNode;
        q.push(leftNode);

        i++;
        if (i < lot.size() - 1)
        {
            Node *rightNode = new Node(lot[i + 1]);
            curNode->right = rightNode;

            q.push(rightNode);
            i++;
        }

        q.pop();

        // i += 2;
    }
}

// void treeFromLevelOrder(Node *root, vector<int> &lot)
// {
//     int i = 0;
//     queue<Node *> q;
//     q.push(root);

//     while (i < lot.size() && !q.empty())
//     {
//         if (i < lot.size() - 2)
//         {
//             Node *curNode = q.front();

//             Node *leftNode = new Node(lot[i + 1]);
//             curNode->left = leftNode;

//             Node *rightNode = new Node(lot[i + 2]);
//             curNode->right = rightNode;

//             q.push(leftNode);
//             q.push(rightNode);
//             q.pop();

//             i += 2;
//         }
//         else if (i < lot.size() - 1)
//         {
//             Node *curNode = q.front();

//             Node *leftNode = new Node(lot[i + 1]);
//             curNode->left = leftNode;

//             q.push(leftNode);
//             q.pop();
//             i++;
//         }
//     }
// }

int countLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int heightBT(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(heightBT(root->left), heightBT(root->right));
}

int diameter(Node *root, map<int, int> &mem)
{
    auto it = mem.find(root->info);
    if (it != mem.end())
    {
        return it->second;
    }

    if (root == NULL)
        return 0;

    // return 1 + diameter(root->left) + diameter(root->right);
    int ansLeftSubtreeMadheAahe = diameter(root->left, mem);
    int andRightSubtreeMadheAahe = diameter(root->right, mem);
    int jarAnsHyaNodeThroughAahe = heightBT(root->left) + heightBT(root->right);
    mem[root->info] = max(ansLeftSubtreeMadheAahe, max(andRightSubtreeMadheAahe, jarAnsHyaNodeThroughAahe));
    return mem[root->info];
}

int main()
{
    Node *root = buildTree(root);
    // vector<int> lot = {1, 2, 4, 4, 7, 6, 78, 9};
    // treeFromLevelOrder(root, lot);
    levelOrderTraversal(root);
    cout << endl;
    cout << countLeafNodes(root) << endl;

    cout << heightBT(root) << endl;
    map<int, int> mem;
    cout << diameter(root, mem) << endl;

    return 0;
}