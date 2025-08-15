// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    // Reorder nodes so all odd-index nodes come first, then even-index nodes.
    // Indices are 1-based: head is index 1 (odd), head->next is index 2 (even), etc.
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;      // to connect after odd list

        while (even && even->next) {
            odd->next  = even->next;    // link next odd
            odd        = odd->next;
            even->next = odd->next;     // link next even
            even       = even->next;
        }
        odd->next = evenHead;           // append even list after odd list
        return head;
    }
};
