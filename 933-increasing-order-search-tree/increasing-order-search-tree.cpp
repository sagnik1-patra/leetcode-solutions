class Solution {
public:
    TreeNode* curr;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        node->left = nullptr;
        curr->right = node;
        curr = node;

        inorder(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        curr = dummy;

        inorder(root);

        return dummy->right;
    }
};
