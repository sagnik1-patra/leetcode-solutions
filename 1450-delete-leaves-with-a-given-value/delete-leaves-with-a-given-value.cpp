class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return NULL;
        
        // Step 1: process children first (post-order)
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        // Step 2: check if current node becomes leaf
        if (!root->left && !root->right && root->val == target) {
            return NULL; // delete this node
        }
        
        return root;
    }
};