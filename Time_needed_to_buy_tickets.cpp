class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int time = tickets[k];
        for (int i = 0; i < tickets.size(); i++)
        {
            if (i < k)
            {
                if (tickets[i] <= tickets[k])
                {
                    time += tickets[i];
                }
                else
                {
                    time += tickets[k];
                }
            }
            else if (i > k)
            {
                if (tickets[i] < tickets[k])
                {
                    time += tickets[i];
                }
                else
                {
                    time += (tickets[k] - 1);
                }
            }
        }
        return time;
    }
};