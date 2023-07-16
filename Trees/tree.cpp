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