class Solution {
public:
    int sumSoFar = 0;

    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;
    }

    void reverseInorder(TreeNode* node) {
        if (!node) return;

        reverseInorder(node->right);

        sumSoFar += node->val;
        node->val = sumSoFar;

        reverseInorder(node->left);
    }
};