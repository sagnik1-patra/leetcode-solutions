class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenTree(root, prev);
    }

private:
    void flattenTree(TreeNode* node, TreeNode*& prev) {
        if (!node) return;

        flattenTree(node->right, prev);
        flattenTree(node->left, prev);

        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
};
