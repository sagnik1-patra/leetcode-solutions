class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit);
    }

    TreeNode* dfs(TreeNode* node, int limit) {
        if (!node) return nullptr;

        limit -= node->val;

        // If leaf node
        if (!node->left && !node->right) {
            return (limit <= 0) ? node : nullptr;
        }

        // Recurse on children
        node->left = dfs(node->left, limit);
        node->right = dfs(node->right, limit);

        // If both children are deleted, delete this node too
        if (!node->left && !node->right) {
            return nullptr;
        }

        return node;
    }
};
