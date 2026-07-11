class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return;

        // Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse 2nd half
        ListNode* second = reverse(slow->next);
        slow->next = nullptr;

        //Merge
        ListNode* first = head;

        while (second)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};