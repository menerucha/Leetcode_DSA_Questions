class Solution
{
public:
    int recur(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (i == text1.size() || j == text2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + recur(i + 1, j + 1, text1, text2, dp);
        }
        ans = max(ans, recur(i, j + 1, text1, text2, dp));
        ans = max(ans, recur(i + 1, j, text1, text2, dp));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return recur(0, 0, text1, text2, dp);
    }
};