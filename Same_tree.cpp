class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool valid = true;
        dfs(p, q, valid);
        return valid;
    }

    void dfs(TreeNode *p, TreeNode *q, bool &valid)
    {
        if (p == NULL && q != NULL)
            valid = false;
        else if (p != NULL && q == NULL)
            valid = false;
        if (p == NULL || q == NULL)
            return;

        if (p->val != q->val)
            valid = false;

        dfs(p->left, q->left, valid);
        dfs(p->right, q->right, valid);
    }
};
