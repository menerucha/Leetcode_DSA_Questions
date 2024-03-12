class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int level = -1;
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }
        while (!q.empty())
        {
            int temp = q.size();
            for (int i = 0; i < temp; i++)
            {
                if (q.front().first - 1 >= 0 && mat[q.front().first - 1][q.front().second] == 1)
                {
                    q.push(make_pair(q.front().first - 1, q.front().second));
                    mat[q.front().first - 1][q.front().second] = level;
                }
                if (q.front().first + 1 < mat.size() && mat[q.front().first + 1][q.front().second] == 1)
                {
                    q.push(make_pair(q.front().first + 1, q.front().second));
                    mat[q.front().first + 1][q.front().second] = level;
                }
                if (q.front().second - 1 >= 0 && mat[q.front().first][q.front().second - 1] == 1)
                {
                    q.push(make_pair(q.front().first, q.front().second - 1));
                    mat[q.front().first][q.front().second - 1] = level;
                }
                if (q.front().second + 1 < mat[0].size() && mat[q.front().first][q.front().second + 1] == 1)
                {
                    q.push(make_pair(q.front().first, q.front().second + 1));
                    mat[q.front().first][q.front().second + 1] = level;
                }
                q.pop();
            }
            level -= 1;
        }
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                mat[i][j] = abs(mat[i][j]);
            }
        }
        return mat;
    }
};