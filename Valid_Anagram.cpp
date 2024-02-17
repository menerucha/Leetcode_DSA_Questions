<<<<<<< HEAD
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> h(26);
        for (int i = 0; i < s.size(); i++)
            h[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++)
        {
            int x = --h[t[i] - 'a'];
            if (x < 0)
                return false;
        }
        return true;
    }
=======
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> h(26);
        for (int i = 0; i < s.size(); i++)
            h[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++)
        {
            int x = --h[t[i] - 'a'];
            if (x < 0)
                return false;
        }
        return true;
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};