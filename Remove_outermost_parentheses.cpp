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
};