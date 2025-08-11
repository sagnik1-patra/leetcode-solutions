/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
        while (curr) {
            if (p->val < curr->val && q->val < curr->val) {
                // Both nodes are in the left subtree
                curr = curr->left;
            } else if (p->val > curr->val && q->val > curr->val) {
                // Both nodes are in the right subtree
                curr = curr->right;
            } else {
                // Nodes are on different sides, or one is equal to current node
                return curr;
            }
        }
        
        return nullptr; // Should never be reached if p and q are guaranteed in the tree
    }
};
