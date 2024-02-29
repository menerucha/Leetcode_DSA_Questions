class Solution
{
public:
    vector<int> recoverArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            vector<int> vis(n, 0);
            ans.clear();
            int l = 0, r = i, k;
            k = nums[r] - nums[l];
            if (k % 2 || k == 0)
                continue;
            while (1)
            {
                while (l < n && vis[l])
                    l++;
                while (r < n && (vis[r] || (nums[l] + k) != nums[r]))
                    r++;
                if (l == n || r == n)
                    break;
                vis[l] = 1;
                vis[r] = 1;
                ans.emplace_back(nums[l] + k / 2);
            }
            int m = ans.size();
            if (2 * m == n)
                break;
        }
        return ans;
    }
};