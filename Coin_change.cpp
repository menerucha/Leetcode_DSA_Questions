class Solution
{
private:
    int solveMemoization(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];
        int minCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveMemoization(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
                minCoins = min(minCoins, ans + 1);
        }
        dp[amount] = minCoins;
        return dp[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int ans = solveMemoization(coins, amount, dp);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};