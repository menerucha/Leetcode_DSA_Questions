class MyHashMap
{
public:
    int v[1000001];
    MyHashMap()
    {
        for (int i = 0; i < 1000001; i++)
        {
            v[i] = -1;
        }
    }
    void put(int key, int value)
    {
        v[key] = value;
    }
    int get(int key)
    {
        return v[key];
    }
    void remove(int key)
    {
        v[key] = -1;
    }
};