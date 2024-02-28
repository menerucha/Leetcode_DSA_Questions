class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root || (!root->left && !root->right))
            return root;
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }
};