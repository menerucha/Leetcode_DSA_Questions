class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            ++level;
        }
        return level;
    }
};