class Solution
{
public:
    int tree[400040];

    int get_mid(int a, int b)
    {
        return a + (b - a) / 2;
    }
    int query(int index, int s, int e, int qs, int qe)
    {
        if (s >= qs and e <= qe)
            return tree[index];
        if (e < qs or s > qe)
            return 0;
        int mid = get_mid(s, e);
        int leftAns = query(2 * index + 1, s, mid, qs, qe);
        int rightAns = query(2 * index + 2, mid + 1, e, qs, qe);
        return leftAns + rightAns;
    }
    void update(int index, int s, int e, int pos)
    {
        if (s == e)
        {
            tree[index]++;
            return;
        }
        int mid = get_mid(s, e);
        if (pos <= mid)
            update(2 * index + 1, s, mid, pos);
        else
            update(2 * index + 2, mid + 1, e, pos);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    int createSortedArray(vector<int> &instructions)
    {
        int cost = 0;
        const int MAXN = 1e5 + 1;
        const int MOD = 1e9 + 7;
        for (auto x : instructions)
        {
            int less_count = query(0, 0, MAXN, 0, x - 1);
            int greater_count = query(0, 0, MAXN, x + 1, MAXN);
            update(0, 0, MAXN, x);
            cost = (cost + min(less_count, greater_count)) % MOD;
        }
        return cost;
    }
};