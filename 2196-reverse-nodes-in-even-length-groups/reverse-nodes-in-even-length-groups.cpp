class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        int group = 2;

        while (prev->next != nullptr) {
            ListNode* curr = prev->next;
            ListNode* temp = curr;

            int count = 0;

            // Count actual nodes in the group
            while (temp != nullptr && count < group) {
                temp = temp->next;
                count++;
            }

            // Reverse if actual group length is even
            if (count % 2 == 0) {
                ListNode* next = temp;
                ListNode* node = curr;

                for (int i = 0; i < count; i++) {
                    ListNode* nxt = node->next;
                    node->next = next;
                    next = node;
                    node = nxt;
                }

                prev->next = next;
                prev = curr;
            }
            else {
                // Move prev to the end of the group
                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }

            group++;
        }

        return head;
    }
};