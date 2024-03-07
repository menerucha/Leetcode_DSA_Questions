class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> memo(n, -1);
        function<int(int)> dp = [&](int i)
        {
            if (i > n || s[i] == '0')
                return 0;
            if (i == n)
                return 1;
            if (memo[i] != -1)
                return memo[i];
            int take1 = dp(i + 1);
            int take2 = s.substr(i, 2) <= "26" ? dp(i + 2) : 0;
            return memo[i] = take1 + take2;
        };
        return dp(0);
    }
};