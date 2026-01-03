class Solution {
public:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        curr = (curr << 1) | node->val;

        // If leaf node, return the binary number formed
        if (!node->left && !node->right)
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
