/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;
        ListNode* nex = nullptr;
        ListNode* pre = &dummy;

        int count = 0;
        while (curr->next) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = pre->next;
            nex = curr->next;

            for (int i = 1; i < k; ++i) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }

            pre = curr;
            count -= k;
        }

        return dummy.next; 
    }
};