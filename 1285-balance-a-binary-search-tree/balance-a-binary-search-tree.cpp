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
    vector<int> arr;
    
    // Step 1: inorder traversal
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    // Step 2: build balanced BST
    TreeNode* build(int l, int r) {
        if (l > r) return NULL;
        
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        
        node->left = build(l, mid - 1);
        node->right = build(mid + 1, r);
        
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, arr.size() - 1);
    }
};