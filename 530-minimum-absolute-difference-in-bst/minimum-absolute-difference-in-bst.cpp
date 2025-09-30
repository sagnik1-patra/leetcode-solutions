class Solution {
public:
    int minDiff = INT_MAX;
    int prevVal = -1;

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (prevVal != -1) {
            minDiff = min(minDiff, node->val - prevVal);
        }
        prevVal = node->val;

        inorder(node->right);
    }
};