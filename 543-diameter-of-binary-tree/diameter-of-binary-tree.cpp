class Solution {
public:
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftH = dfs(node->left);
        int rightH = dfs(node->right);

        // update diameter (number of edges)
        maxDiameter = max(maxDiameter, leftH + rightH);

        // return height
        return 1 + max(leftH, rightH);
    }
};