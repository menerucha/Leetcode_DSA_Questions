class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *curr = head;
        int size = 1;
        while (curr->next != nullptr)
        {
            curr = curr->next;
            ++size;
        }
        curr->next = head;
        int i = size - (k % size);
        while (i > 1)
        {
            head = head->next;
            i--;
        }
        curr = head->next;
        head->next = nullptr;
        return curr;
    }
};