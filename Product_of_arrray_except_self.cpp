class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        ans[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            ans[i] = nums[i] * ans[i + 1];
        }
        int p = 1;
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = p * ans[i + 1];
            p = p * nums[i];
        }
        ans[n - 1] = p;
        return ans;
    }
};