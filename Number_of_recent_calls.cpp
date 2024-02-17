<<<<<<< HEAD
class RecentCounter
{
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t)
    {
        int st = t - 3000, c = 0;
        q.push(t);

        while (!q.empty())
        {
            if (q.front() < st)
                q.pop();
            else
                break;
        }

        return q.size();
    }
=======
class RecentCounter
{
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t)
    {
        int st = t - 3000, c = 0;
        q.push(t);

        while (!q.empty())
        {
            if (q.front() < st)
                q.pop();
            else
                break;
        }

        return q.size();
    }
>>>>>>> 65a4e95468639fd8339b68a80f54ff05428a8998
};