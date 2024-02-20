class Solution
{
public:
    void merger(vector<int> &nums, int start, int end)
    {
        int mid = start + (end - start) / 2;
        int leftlen = mid - start + 1, rightlen = end - mid;
        vector<int> leftArray(leftlen);
        vector<int> rightArray(rightlen);
        int k = start;
        for (int i = 0; i < leftlen; i++)
        {
            leftArray[i] = nums[k++];
        }
        for (int i = 0; i < rightlen; i++)
        {
            rightArray[i] = nums[k++];
        }
        int leftInd = 0, rightInd = 0, mainInd = start;
        while (leftInd < leftlen && rightInd < rightlen)
        {
            if (leftArray[leftInd] < rightArray[rightInd])
            {
                nums[mainInd++] = leftArray[leftInd++];
            }
            else
            {
                nums[mainInd++] = rightArray[rightInd++];
            }
        }
        while (leftInd < leftlen)
        {
            nums[mainInd++] = leftArray[leftInd++];
        }
        while (rightInd < rightlen)
        {
            nums[mainInd++] = rightArray[rightInd++];
        }
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merger(nums, start, end);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        mergeSort(nums, start, end);
        return nums;
    }
};