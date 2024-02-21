typedef long long ll;
const int offset = 2E4;

class Solution
{
private:
    ll maxN;
    vector<ll> seg;
    void seg_update(int i, int low, int high, int node)
    {
        if (low == high)
        {
            seg[i]++;
            return;
        }
        int mid = low + (high - low) / 2;
        if (node <= mid)
        {
            seg_update(2 * i + 1, low, mid, node);
        }
        else
        {
            seg_update(2 * i + 2, mid + 1, high, node);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    ll seg_query(int i, int low, int high, int l, int r)
    {
        if (low > r || high < l)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return seg[i];
        }
        ll mid = low + (high - low) / 2;
        ll left = seg_query(2 * i + 1, low, mid, l, r);
        ll right = seg_query(2 * i + 2, mid + 1, high, l, r);
        return left + right;
    }

public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        int n = nums1.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = nums1[i] - nums2[i] + offset;
        }
        maxN = 2 * offset + 1;
        seg.resize(maxN * 4 + 10, 0);
        ll ans = 0;
        for (auto it : v)
        {
            ans += seg_query(0, 0, maxN - 1, 0, it + diff);
            seg_update(0, 0, maxN - 1, it);
        }
        return ans;
    }
};