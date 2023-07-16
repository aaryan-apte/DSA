#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->info << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->info << " ";
    preOrder(root->left);
    preOrder(root->right);
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

void reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    stack<Node *> st;

    q.push(root);
    while (!q.empty())
    {
        Node *curNode = q.front();
        st.push(q.front());
        q.pop();

        // q.pop();
        if (curNode->right != NULL)
        {
            q.push(curNode->right);
        }
        if (curNode->left != NULL)
            q.push(curNode->left);
    }
    while (!st.empty())
    {
        cout << st.top()->info << " ";
        st.pop();
    }
}

void inOrderIterative(Node *root)
{
    stack<Node *> st;

    st.push(root);
    while (!st.empty())
    {
        Node *curNode = st.top();
        while (curNode->left != NULL)
        {
            curNode = curNode->left;
            st.push(curNode);
        }
        cout << curNode->info << " ";
        if (curNode->right != NULL)
        {
            curNode = curNode->right;
            st.push(curNode);
        }
    }
}

int main()
{
    Node *root = buildTree(root);
    // levelOrderTraversal(root);

    // cout << endl
    //      << "Inorder:\n";
    // inOrder(root);
    // cout << endl
    //      << "Preorder:\n";
    // preOrder(root);
    // cout << endl
    //      << "Postorder:\n";
    // postOrder(root);

    // {1 2 4 -1 78 -1 -1 7 9 -1 -1 -1 4 6 -1 -1 -1};

    reverseLevelOrder(root);

    return 0;
}