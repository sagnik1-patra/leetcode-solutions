class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node before head to simplify edge cases
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                // Skip the node with value == val
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory
            } else {
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Free dummy node memory
        return newHead;
    }
};
