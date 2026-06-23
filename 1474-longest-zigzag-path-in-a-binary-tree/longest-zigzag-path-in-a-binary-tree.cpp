/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* node, int leftLen, int rightLen) {
        if (!node) return;
        
        ans = max(ans, max(leftLen, rightLen));
        
        // go left → reset left chain, extend right chain
        dfs(node->left, 0, leftLen + 1);
        
        // go right → reset right chain, extend left chain
        dfs(node->right, rightLen + 1, 0);
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};