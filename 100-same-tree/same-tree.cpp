class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both are null
        if (!p && !q) return true;

        // If one is null and the other isn't, or values don't match
        if (!p || !q || p->val != q->val) return false;

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
