
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node before head to handle edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != nullptr) {
            // Skip all nodes with the same value
            if (head->next != nullptr && head->val == head->next->val) {
                int dupVal = head->val;
                while (head != nullptr && head->val == dupVal) {
                    head = head->next;
                }
                prev->next = head;
            } else {
                prev = prev->next;
                head = head->next;
            }
        }

        return dummy->next;
    }
};
