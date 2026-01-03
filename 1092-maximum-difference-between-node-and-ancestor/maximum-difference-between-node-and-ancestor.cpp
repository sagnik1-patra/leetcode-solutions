class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return;

        // Update maximum difference
        ans = max(ans, max(abs(node->val - minVal), abs(node->val - maxVal)));

        // Update min and max for this path
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        dfs(node->left, minVal, maxVal);
        dfs(node->right, minVal, maxVal);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
