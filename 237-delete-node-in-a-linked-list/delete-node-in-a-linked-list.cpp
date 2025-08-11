/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy value of next node to current node
        node->val = node->next->val;
        // Bypass the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        // Free memory of the removed node (optional)
        delete temp;
    }
};
