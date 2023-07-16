#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

void zigZagTraversal(Node *root)
{
    int level = 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            level++;
            continue;
        }

        Node *cur = q.front();
        if (level % 2 == 0)
        {
            if (cur->left != NULL)
                q.push(cur->left);

            if (cur->right != NULL)
                q.push(cur->right);

            cout << cur->info << " ";
            q.pop();
        }
        else
        {
            // if (cur->right != NULL)
            //     q.push(cur->right);

            // if (cur->left != NULL)
            //     q.push(cur->left);

            // cout << cur->info << " ";
            // q.pop();
            stack<Node *> st;
            while (!q.empty() && q.front() != NULL)
            {
                cur = q.front();
                if (cur->left != NULL)
                    q.push(cur->left);

                if (cur->right != NULL)
                    q.push(cur->right);

                st.push(q.front());
                q.pop();
            }
            while (!st.empty())
            {
                cout << st.top()->info << " ";
                st.pop();
            }
        }
    }
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

int main()
{
    Node *root = buildTree(root);
    cout << "Zig zag:\n";
    zigZagTraversal(root);
    cout << endl;
    cout << "Lvl\n";
    levelOrderTraversal(root);

    return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1