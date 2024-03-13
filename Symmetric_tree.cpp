class Solution
{
public:
    bool isMirror(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
        {
            return true;
        }
        if (l == NULL || r == NULL)
        {
            return false;
        }
        return (l->val == r->val) && isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};