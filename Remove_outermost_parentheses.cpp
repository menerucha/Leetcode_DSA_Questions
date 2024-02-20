<<<<<<< HEAD
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";
        vector<char> outer;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' and outer.size() != 0)
            {
                result.append("(");
                outer.push_back('(');
            }
            else if (s[i] == '(' and outer.size() == 0)
            {
                outer.push_back('(');
            }
            else if (s[i] == ')' and outer.size() > 1)
            {
                result.append(")");
                outer.pop_back();
            }
            else if (s[i] == ')' and outer.size() == 1)
            {
                outer.pop_back();
            }
        }
        return result;
    }
=======
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";
        vector<char> outer;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' and outer.size() != 0)
            {
                result.append("(");
                outer.push_back('(');
            }
            else if (s[i] == '(' and outer.size() == 0)
            {
                outer.push_back('(');
            }
            else if (s[i] == ')' and outer.size() > 1)
            {
                result.append(")");
                outer.pop_back();
            }
            else if (s[i] == ')' and outer.size() == 1)
            {
                outer.pop_back();
            }
        }
        return result;
    }
>>>>>>> 3a9d63e5f730caf996f177773888a27003be2394
};