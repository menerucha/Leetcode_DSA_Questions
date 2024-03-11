class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        stack<pair<TreeNode *, pair<long long, long long>>> stack;
        stack.push({root, {LLONG_MIN, LLONG_MAX}});
        while (!stack.empty())
        {
            TreeNode *node = stack.top().first;
            long long minval = stack.top().second.first;
            long long maxval = stack.top().second.second;
            stack.pop();
            if (node->val <= minval || node->val >= maxval)
                return false;
            if (node->left)
                stack.push({node->left, {minval, node->val}});
            if (node->right)
                stack.push({node->right, {node->val, maxval}});
        }
        return true;
    }
};