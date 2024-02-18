<<<<<<< HEAD
class STree
{
public:
    vector<int> seg;
    STree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(vector<int> &freq, int ind, int low, int high)
    {
        if (low == high)
        {
            seg[ind] = freq[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(freq, 2 * ind + 1, low, mid);
        build(freq, 2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] += val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r)
    {

        if (high < l or low > r)
            return 0;

        if (low >= l and high <= r)
            return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = 20001;
        vector<int> freq(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 10000]++;
        }
        STree st(n);
        st.build(freq, 0, 0, n - 1);
        cout << st.seg[0];
        vector<int> cnt;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 10000]--;
            st.update(0, 0, n - 1, nums[i] + 10000, -1);
            cnt.push_back(st.query(0, 0, n - 1, 0, nums[i] + 10000 - 1));
        }
        return cnt;
    }

    vector<int> res;
    void merge(vector<pair<int, int>> &nums, int low, int high, int mid)
    {
        int l = mid - low + 1, r = high - mid;
        vector<pair<int, int>> left, right;
        for (int i = low; i <= mid; i++)
            left.push_back(nums[i]);
        for (int j = mid + 1; j <= high; j++)
            right.push_back(nums[j]);
        int k = low, i = 0, j = 0;
        while (i < l and j < r)
        {
            if (left[i].first > right[j].first)
            {
                nums[k] = right[j];
                j++;
            }
            else
            {
                nums[k] = left[i];
                res[left[i].second] += j;
                i++;
            }
            k++;
        }
        while (i < l)
        {
            nums[k++] = left[i];
            res[left[i++].second] += j;
        }
        while (j < r)
            nums[k++] = right[j++];
        return;
    }

    void mergeSort(vector<pair<int, int>> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, high, mid);
    }
=======
class STree
{
public:
    vector<int> seg;
    STree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(vector<int> &freq, int ind, int low, int high)
    {
        if (low == high)
        {
            seg[ind] = freq[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(freq, 2 * ind + 1, low, mid);
        build(freq, 2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] += val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r)
    {

        if (high < l or low > r)
            return 0;

        if (low >= l and high <= r)
            return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = 20001;
        vector<int> freq(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 10000]++;
        }
        STree st(n);
        st.build(freq, 0, 0, n - 1);
        cout << st.seg[0];
        vector<int> cnt;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] + 10000]--;
            st.update(0, 0, n - 1, nums[i] + 10000, -1);
            cnt.push_back(st.query(0, 0, n - 1, 0, nums[i] + 10000 - 1));
        }
        return cnt;
    }

    vector<int> res;
    void merge(vector<pair<int, int>> &nums, int low, int high, int mid)
    {
        int l = mid - low + 1, r = high - mid;
        vector<pair<int, int>> left, right;
        for (int i = low; i <= mid; i++)
            left.push_back(nums[i]);
        for (int j = mid + 1; j <= high; j++)
            right.push_back(nums[j]);
        int k = low, i = 0, j = 0;
        while (i < l and j < r)
        {
            if (left[i].first > right[j].first)
            {
                nums[k] = right[j];
                j++;
            }
            else
            {
                nums[k] = left[i];
                res[left[i].second] += j;
                i++;
            }
            k++;
        }
        while (i < l)
        {
            nums[k++] = left[i];
            res[left[i++].second] += j;
        }
        while (j < r)
            nums[k++] = right[j++];
        return;
    }

    void mergeSort(vector<pair<int, int>> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, high, mid);
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};