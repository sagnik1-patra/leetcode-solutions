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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return NULL;
        
        // found target
        if (original == target) return cloned;
        
        // search left
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;
        
        // search right
        return getTargetCopy(original->right, cloned->right, target);
    }
};