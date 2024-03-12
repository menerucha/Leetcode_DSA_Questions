class Solution
{
public:
    int leastBricks(vector<vector<int>> &A)
    {
        unordered_map<long long, int> m;
        for (auto w : A)
        {
            long long sum = 0;
            for (int i = 0; i < w.size() - 1; i++)
            {
                sum += w[i];
                m[sum]++;
            }
        }
        int ans = 0;
        for (auto [k, v] : m)
            ans = max(ans, v);
        return A.size() - ans;
    }
};