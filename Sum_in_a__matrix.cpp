class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        for (int i = 0; i < n; i++)
        {
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }
        int ans = 0, temp = 0;
        for (int i = 0; i < m; i++)
        {
            temp = 0;
            for (int j = 0; j < n; j++)
            {
                temp = max(temp, nums[j][i]);
            }
            ans += temp;
        }
        return ans;
    }
};