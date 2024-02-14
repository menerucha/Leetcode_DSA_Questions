class Solution
{
    int dp[46];

public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return dp[n] = n;
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};