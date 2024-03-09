class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        map<int, int> indegree;
        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        int res, fre = 0;
        for (auto i : indegree)
        {
            if (i.second > fre)
            {
                fre = i.second;
                res = i.first;
            }
        }
        return res;
    }
};