<<<<<<< HEAD
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
=======
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
>>>>>>> e551094786703a77c6b2f792e91190d21c53fccf
};