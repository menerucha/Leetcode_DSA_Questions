<<<<<<< HEAD
class Solution
{
private:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL)
        {
            inorder(root->left, ans);
        }
        ans.push_back(root->val);
        if (root->right != NULL)
            inorder(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);

        return ans;
    }
=======
class Solution
{
private:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL)
        {
            inorder(root->left, ans);
        }
        ans.push_back(root->val);
        if (root->right != NULL)
            inorder(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);

        return ans;
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};