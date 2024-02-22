class Solution
{
public:
    int solve(string &s)
    {
        int n = s.size();
        int maxi = 0;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                temp++;
            }
            else if (s[i] == ')')
            {
                maxi = max(maxi, temp);
                temp--;
            }
        }

        return maxi;
    }

    int maxDepth(string s)
    {
        return solve(s);
    }
};