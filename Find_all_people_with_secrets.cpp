class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<vector<pair<int, int>>> g(n);
        for (auto &m : meetings)
            g[m[0]].push_back({m[1], m[2]}), g[m[1]].push_back({m[0], m[2]});

        g[0].push_back({firstPerson, 0});

        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            auto [ct, to] = q.top();
            q.pop();
            if (vis[to])
                continue;
            vis[to] = 1;

            for (auto [next, time] : g[to])
                if (vis[next] == 0 && time >= ct)
                    q.push({time, next});
        }

        int id = 0;
        for (int i = 0; i != n; i++)
            if (vis[i])
                vis[id++] = i;

        vis.resize(id);
        return vis;
    }
};