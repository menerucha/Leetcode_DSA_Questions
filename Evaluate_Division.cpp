class Solution
{
public:
    // Global variables
    bool z = false;
    map<string, int> visited;

    // Recurssive Function
    double cal(map<string, vector<pair<string, double>>> m, string itr, string target, double val = 1)
    {

        if (visited[itr] == 1)
            return 1;
        visited[itr] = 1;
        double ans = 1;
        if (target == itr)
        {
            z = true;
            return val;
        }

        // Recurssion is from here
        vector<pair<string, double>> o = m[itr];
        for (int i = 0; i < o.size(); i++)
        {
            if (!z)
                ans *= cal(m, m[itr][i].first, target, m[itr][i].second);
        }
        if (z)
            return ans * val;
        return ans;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, vector<pair<string, double>>> m;
        // Storing values in map
        for (int i = 0; i < equations.size(); i++)
        {
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        vector<double> ans;

        // Initiation
        for (int i = 0; i < queries.size(); i++)
        {
            visited.clear();
            double p = 0;
            z = false;

            p = (cal(m, queries[i][0], queries[i][1]));
            if (queries[i][0] == queries[i][1] && m[queries[i][0]].size() == 0)
                z = false; // edge case which I think should get corrected by Leetcode in near future
            if (z)
                ans.push_back(p);
            else
                ans.push_back(-1.0);
        }
        return ans;
    }
};