<<<<<<< HEAD
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
=======
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
>>>>>>> 6c811e6a51d2cf42f27eaaea6ddf4a8e2f5de596
};