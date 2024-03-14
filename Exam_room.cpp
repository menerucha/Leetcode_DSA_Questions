class ExamRoom
{
public:
    set<int> seats;
    int capacity;
    ExamRoom(int n)
    {
        capacity = n;
    }
    int seat()
    {
        if (seats.empty())
        {
            seats.insert(0);
            return 0;
        }
        else
        {
            int max = 0, pos = 0;
            auto it = seats.begin();
            auto prev = it;
            if (*it != 0)
            {
                max = 1;
                pos = 0;
            }
            else
            {
                ++it;
                for (; it != seats.end(); ++it)
                {
                    int diff = (*it - *prev) / 2;
                    if (diff > max)
                    {
                        max = diff;
                        pos = *prev + diff;
                    }
                    prev = it;
                }
            }
            if (capacity - 1 - *seats.rbegin() > max)
            {
                pos = capacity - 1;
            }
            seats.insert(pos);
            return pos;
        }
    }
    void leave(int p)
    {
        seats.erase(p);
    }
};