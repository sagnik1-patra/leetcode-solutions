class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next; // store next node
            curr->next = prev;           // reverse current node's pointer
            prev = curr;                 // move prev to current
            curr = next;                 // move to next node
        }
        
        return prev;
    }
};
