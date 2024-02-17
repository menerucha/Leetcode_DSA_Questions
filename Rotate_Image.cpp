<<<<<<< HEAD
class Solution
{
public:
    void rotate(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
=======
class Solution
{
public:
    void rotate(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};