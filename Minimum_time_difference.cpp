class Solution
{
public:
    int findMinDifference(vector<string> &timepoints)
    {
        vector<int> ans;
        for (int i = 0; i < timepoints.size(); i++)
        {
            string hours = timepoints[i].substr(0, 2);
            string minutes = timepoints[i].substr(3, 2);
            int hrs = stoi(hours);
            int min = stoi(minutes);
            ans.push_back(hrs * 60 + min);
        }
        sort(ans.begin(), ans.end());
        int mindiff = INT_MAX;
        for (int j = 0; j < ans.size() - 1; j++)
        {
            if (ans[j + 1] - ans[j] < mindiff)
            {
                mindiff = ans[j + 1] - ans[j];
            }
        }
        int lastdiff = (ans[0] + 1440) - ans[ans.size() - 1];
        return min(lastdiff, mindiff);
    }
};