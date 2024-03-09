class Solution
{
public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<vector<unsigned int>>> status(
            2, vector<vector<unsigned int>>(n, vector<unsigned int>(n)));

        function<void(int, int, int)> visit = [&](int i, int j, int k)
        {
            if (status[0][1][2] & 3)
                return;
            auto &edges = graph[i ? j : k];
            for (int q : edges)
            {
                int i1 = (i + 1) & 1, j1 = i ? q : j, k1 = i ? k : q,
                    s = status[i][j][k] & 3;
                unsigned int &s1 = status[i1][j1][k1];
                if ((s1 & 3) == 0 && (s == 2 - i || s == i + 1 && (s1 -= 4) < 4))
                {
                    s1 = s;
                    visit(i1, j1, k1);
                }
            }
        };

        for (int i = 1; i < n; i++)
        {
            status[0][i][i] = status[1][i][i] = 2;
            status[1][0][i] = status[0][i][0] = 1;

            for (int j = 1; j < n; j++)
            {
                status[0][i][j] += graph[i].size() * 4;
                status[1][i][j] += graph[j].size() * 4;
            }
        }

        for (int i = 1; i < n; i++)
        {
            visit(0, i, i);
            visit(1, i, i);
            visit(1, 0, i);
            visit(0, i, 0);
        }
        int res = status[0][1][2] & 3;
        return res;
    }
};