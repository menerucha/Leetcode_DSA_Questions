<<<<<<< HEAD
class Solution
{
public:
    int reverse(int x)
    {
        long ans = 0;
        while (x)
        {
            int digit = x % 10;
            ans = ans * 10 + digit;
            x = x / 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
        return (int)ans;
    }
=======
class Solution
{
public:
    int reverse(int x)
    {
        long ans = 0;
        while (x)
        {
            int digit = x % 10;
            ans = ans * 10 + digit;
            x = x / 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
        return (int)ans;
    }
>>>>>>> 65b0bf377d8f02d16cd510765df641019723fc4d
};