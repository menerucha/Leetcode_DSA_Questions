class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int num = pow(2, nums.size()) - 1;
        for (int i = 0; i <= num; i++)
        {
            vector<int> st;
            int index = 0, result = num & i;
            while (index < nums.size() && result)
            {
                if ((result & 1) == 1)
                    st.push_back(nums[index]);
                result = result >> 1;
                index++;
            }
            ans.push_back(st);
        }
        return ans;
    }
};