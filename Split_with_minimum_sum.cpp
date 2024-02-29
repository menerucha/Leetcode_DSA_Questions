class Solution
{
public:
    int splitNum(int num)
    {
        int x = 0, y = 0, k = 0, i;
        vector<int> v(10, 0);
        while (num)
        {
            x = num % 10;
            v[x]++;
            num /= 10;
        }
        x = 0, y = 0;
        for (i = 0; i < 10; i++)
        {
            while (v[i]--)
            {
                if (k & 1)
                {
                    x = x * 10 + i;
                }
                else
                {
                    y = y * 10 + i;
                }
                k ^= 1;
            }
        }
        return x + y;
    }
};