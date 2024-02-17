class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            bool flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == s[i] && i != j)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                return i;
            }
        }
        return -1;
    }
};