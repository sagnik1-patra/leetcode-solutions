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
    
    // returns {isBST, min, max, sum}
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, INT_MAX, INT_MIN, 0};
        }
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        // check BST condition
        if (left[0] && right[0] && root->val > left[2] && root->val < right[1]) {
            int sum = left[3] + right[3] + root->val;
            
            ans = max(ans, sum);
            
            int minVal = min(root->val, left[1]);
            int maxVal = max(root->val, right[2]);
            
            return {1, minVal, maxVal, sum};
        }
        
        // not BST
        return {0, 0, 0, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};