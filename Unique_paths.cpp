class Solution
{
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 and j == 0)
            return 1;
        if (i < 0 or j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int t = solve(i - 1, j, dp);
        int l = solve(i, j - 1, dp);
        return dp[i][j] = t + l;
    }

public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, dp);
    }
};