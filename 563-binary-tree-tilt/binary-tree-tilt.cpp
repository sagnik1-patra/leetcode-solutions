/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int totalTilt = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return totalTilt;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        totalTilt += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
};