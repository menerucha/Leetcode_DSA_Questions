class Solution
{
public:
    int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {
        if (j - i <= 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int temp = INT_MIN;
        for (int k = i + 1; k < j; k++)
        {
            int x = 0, y = 0;
            int z = v[i] * v[k] * v[j] + solve(i, k, v, dp) + solve(k, j, v, dp);
            temp = max(temp, z);
        }
        return dp[i][j] = temp;
    }
    int maxCoins(vector<int> &nums)
    {
        vector<int> v;
        v.push_back(1);
        for (auto it : nums)
            v.push_back(it);
        v.push_back(1);
        vector<vector<int>> dp(v.size(), vector<int>(v.size(), -1));
        return solve(0, v.size() - 1, v, dp);
    }
};