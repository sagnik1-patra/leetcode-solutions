class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0); // Dummy head for < x
        ListNode afterHead(0);  // Dummy head for >= x

        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr;               // End the 'after' list
        before->next = afterHead.next;       // Connect 'before' and 'after'

        return beforeHead.next;              // Return the head of the partitioned list
    }
};
