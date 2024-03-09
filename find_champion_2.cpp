class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 0)
            {
                if (ans != -1)
                    return -1;
                ans = i;
            }
        }
        return ans;
    }
};