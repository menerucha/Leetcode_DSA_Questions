class Solution
{
private:
    static ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp = nullptr;
        while (curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
            return nullptr;
        ListNode *newHead = reverseList(head);
        ListNode *prev = nullptr;
        ListNode *curr = newHead;
        while (--n > 0)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == nullptr)
        {
            prev = curr;
            curr = curr->next;
            prev->next = nullptr;
            head = reverseList(curr);
        }
        else
        {
            prev->next = curr->next;
            curr->next = nullptr;
            head = reverseList(newHead);
        }
        return head;
    }
};
