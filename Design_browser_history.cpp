class BrowserHistory
{
public:
    vector<string> a;
    int cur;
    BrowserHistory(string homepage)
    {
        a.push_back(homepage);
        cur = 0;
    }
    void visit(string url)
    {
        a.resize(cur + 1);
        a.push_back(url);
        cur++;
    }
    string back(int steps)
    {
        int jump = cur - steps;
        if (jump >= 0)
        {
            cur = jump;
            return a[jump];
        }
        else
        {
            cur = 0;
            return a.front();
        }
    }
    string forward(int steps)
    {
        int jump = cur + steps;
        if (jump < a.size())
        {
            cur = jump;
            return a[jump];
        }
        else
        {
            cur = a.size() - 1;
            return a.back();
        }
    }
};