class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  // Dummy node before the head
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;
            ListNode* next = curr->next;

            // Find the correct position to insert current node
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert current node between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to next node
            curr = next;
        }

        return dummy->next;
    }
};
