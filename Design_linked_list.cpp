class MyLinkedList
{
public:
    MyLinkedList()
    {
        start = end = new Node(-1);
        connect(start, end);
    }
    int get(int index)
    {
        return advance(start->next, index)->val;
    }
    void addAtHead(int val)
    {
        add(start, new Node(val), start->next);
    }
    void addAtTail(int val)
    {
        add(end->prev, new Node(val), end);
    }
    void addAtIndex(int index, int val)
    {
        Node *cur = advance(start->next, index);
        if (index)
            return;
        add(cur->prev, new Node(val), cur);
    }
    void deleteAtIndex(int index)
    {
        Node *cur = advance(start->next, index);
        if (cur == end)
            return;
        connect(cur->prev, cur->next);
        delete cur;
    }

private:
    struct Node
    {
        Node *next, *prev;
        int val;
        Node(int _val) : val(_val)
        {
            next = prev = NULL;
        }
    };
    void connect(Node *l, Node *r)
    {
        l->next = r;
        r->prev = l;
    }
    void add(Node *l, Node *mid, Node *r)
    {
        connect(l, mid);
        connect(mid, r);
    }
    Node *advance(Node *cur, int &i)
    {
        while (cur != end && i)
        {
            cur = cur->next;
            --i;
        }
        return cur;
    }
    Node *start, *end;
};