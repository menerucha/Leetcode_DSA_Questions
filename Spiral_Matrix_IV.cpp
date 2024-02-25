class Solution
{
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode *head)
    {
        vector<vector<int>> res(n, vector<int>(m, -1));
        int i = 0, j = 0;
        while (head != NULL)
        {
            if (j < m)
            {
                while (head != NULL and j < m and res[i][j] == -1)
                {
                    res[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                i++;
                j--;
            }
            if (i < n)
            {
                while (head != NULL and i < n and res[i][j] == -1)
                {
                    res[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }
            if (j >= 0)
            {
                while (head != NULL and j >= 0 and res[i][j] == -1)
                {
                    res[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                i--;
                j++;
            }
            if (i >= 0)
            {
                while (head != NULL and i >= 0 and res[i][j] == -1)
                {
                    res[i][j] = head->val;
                    head = head->next;
                    i--;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};