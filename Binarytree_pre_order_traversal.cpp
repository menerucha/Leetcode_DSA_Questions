<<<<<<< HEAD
class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder_Ka_Traversal;
        preorder(root, preorder_Ka_Traversal);
        return preorder_Ka_Traversal;
    }
=======
class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder_Ka_Traversal;
        preorder(root, preorder_Ka_Traversal);
        return preorder_Ka_Traversal;
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};