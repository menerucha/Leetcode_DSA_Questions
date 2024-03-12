class Solution
{
public:
    int solve(int l, int r, vector<int> &boxes, int k, int dp[101][101][101])
    {
        if (l > r)
            return 0;
        int k_here = k;
        int l_here = l;
        if (dp[l][r][k_here] >= 0)
            return dp[l][r][k];
        while (l + 1 <= r && boxes[l] == boxes[l + 1])
        {
            k++;
            l++;
        }
        int ans = (k + 1) * (k + 1) + solve(l + 1, r, boxes, 0, dp);
        for (int m = l + 1; m <= r; m++)
        {
            if (boxes[l] == boxes[m])
            {
                ans = max(ans, solve(m, r, boxes, k + 1, dp) + solve(l + 1, m - 1, boxes, 0, dp));
            }
        }
        return dp[l_here][r][k_here] = ans;
    }
    int removeBoxes(vector<int> &boxes)
    {
        int dp[101][101][101];
        memset(dp, -1, sizeof(dp));
        int n = boxes.size();
        return solve(0, n - 1, boxes, 0, dp);
    }
};