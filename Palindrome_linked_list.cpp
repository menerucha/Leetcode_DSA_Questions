class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {

        ListNode *slow = head, *fast = head, *tem = head;

        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        slow = reverse(slow);
        while (slow)
        {
            if (tem->val != slow->val)
                return false;
            tem = tem->next;
            slow = slow->next;
        }
        return true;
    }
};