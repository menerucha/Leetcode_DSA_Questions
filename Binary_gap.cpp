class Solution
{
public:
    int binaryGap(int n)
    {
        string str = bitset<32>(n).to_string();
        int a = -1, b = -1, inputSize = str.size(), ans = -1, index = -1;
        for (int i = 0; i < inputSize; ++i)
        {
            if (str[i] == '1')
            {
                if (a < 0)
                {
                    a = i;
                }
                else if (b < 0)
                {
                    b = i;
                    index = i + 1;
                    ans = max(ans, b - a);
                    break;
                }
            }
        }
        if (a < 0 || b < 0)
        {
            return 0;
        }
        for (int i = index; i < inputSize; ++i)
        {
            if (str[i] == '1')
            {
                a = b;
                b = i;
                ans = max(ans, b - a);
            }
        }
        if (a > 0 && b > 0)
        {
            return ans;
        }
        return 0;
    }
};