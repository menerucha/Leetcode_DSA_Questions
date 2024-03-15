class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < items1.size(); i++)
            mp[items1[i][0]] = items1[i][1];
        for (int i = 0; i < items2.size(); i++)
        {
            if (mp.find(items2[i][0]) != mp.end())
                mp[items2[i][0]] = mp[items2[i][0]] + items2[i][1];
            else
                mp[items2[i][0]] = items2[i][1];
        }
        vector<vector<int>> ret;
        for (auto it : mp)
            ret.push_back({it.first, it.second});
        sort(ret.begin(), ret.end());
        return ret;
    }
};