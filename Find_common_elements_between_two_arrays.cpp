class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(2);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    ans[0]++;
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums1[j] == nums2[i])
                {
                    ans[1]++;
                    break;
                }
            }
        }
        return ans;
    }
};