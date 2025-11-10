class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        // Recursively prune left and right subtrees first
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // If current node and both subtrees contain no '1', remove this node
        if (!root->left && !root->right && root->val == 0)
            return nullptr;

        return root;
    }
};