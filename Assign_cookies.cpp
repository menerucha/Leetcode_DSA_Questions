<<<<<<< HEAD
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;
        int z = 0;
        int m = 0;
        int n = s.size();
        while (z < s.size() && m < g.size())
        {
            if (s[z] >= g[m])
            {
                count++;
                z++;
                m++;
            }
            else
            {
                z++;
            }
        }
        return count;
    }
=======
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;
        int z = 0;
        int m = 0;
        int n = s.size();
        while (z < s.size() && m < g.size())
        {
            if (s[z] >= g[m])
            {
                count++;
                z++;
                m++;
            }
            else
            {
                z++;
            }
        }
        return count;
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};