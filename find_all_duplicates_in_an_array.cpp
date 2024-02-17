<<<<<<< HEAD
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        set<int> st;
        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            if (st.count(nums[i]))
            {
                v.push_back(nums[i]);
            }
            else
            {
                st.insert(nums[i]);
            }
        }
        return v;
    }
=======
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        set<int> st;
        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            if (st.count(nums[i]))
            {
                v.push_back(nums[i]);
            }
            else
            {
                st.insert(nums[i]);
            }
        }
        return v;
    }
>>>>>>> b06b1fa5234f12fd88fa8ab77cfbb9a233745c6f
};