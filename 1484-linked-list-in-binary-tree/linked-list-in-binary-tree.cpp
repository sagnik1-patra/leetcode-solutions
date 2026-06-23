/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    // Step 2: check matching path
    bool match(ListNode* head, TreeNode* root) {
        if (!head) return true;       // matched full list
        if (!root) return false;      // tree ended early
        
        if (head->val != root->val) return false;
        
        return match(head->next, root->left) ||
               match(head->next, root->right);
    }
    
    // Step 1: try from every node
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        
        return match(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};