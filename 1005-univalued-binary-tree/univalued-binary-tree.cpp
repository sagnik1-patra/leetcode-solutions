class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        return dfs(root, root->val);
    }

    bool dfs(TreeNode* node, int val) {
        if (!node) return true;
        if (node->val != val) return false;
        return dfs(node->left, val) && dfs(node->right, val);
    }
};
