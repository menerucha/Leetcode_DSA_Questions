<<<<<<< HEAD
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> q;
        for (auto i : students)
        {
            q.push(i);
        }
        int i = 0, c = 0;
        while (c < q.size() && i < sandwiches.size())
        {
            if (q.front() == sandwiches[i])
            {
                q.pop();
                i++;
                c = 0;
            }
            else
            {
                int val = q.front();
                q.pop();
                q.push(val);
                c++;
            }
        }
        return q.size();
    }
=======
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> q;
        for (auto i : students)
        {
            q.push(i);
        }
        int i = 0, c = 0;
        while (c < q.size() && i < sandwiches.size())
        {
            if (q.front() == sandwiches[i])
            {
                q.pop();
                i++;
                c = 0;
            }
            else
            {
                int val = q.front();
                q.pop();
                q.push(val);
                c++;
            }
        }
        return q.size();
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};