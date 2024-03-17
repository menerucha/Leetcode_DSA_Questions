class LRUCache
{
private:
    struct node
    {
        int ke;
        int vl;
        node *next;
        node *prev;
        node(int k, int v)
        {
            ke = k;
            vl = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, node *> mp;
    int cap;
    node *head;
    node *tail;

private:
    void addNode(node *newNode)
    {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
    }
    void deleteNode(node *del)
    {
        del->prev->next = del->next;
        del->next->prev = del->prev;
        del->next = nullptr;
        del->prev = nullptr;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        deleteNode(mp[key]);
        addNode(mp[key]);
        return mp[key]->vl;
    }
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            deleteNode(mp[key]);
            addNode(mp[key]);
            mp[key]->vl = value;
            return;
        }
        if (cap == mp.size())
        {
            mp.erase(tail->prev->ke);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        mp[key] = head->next;
        return;
    }
};