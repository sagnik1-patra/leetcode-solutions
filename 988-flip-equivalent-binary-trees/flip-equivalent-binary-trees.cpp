class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // both null
        if (!root1 && !root2) return true;

        // one null or values differ
        if (!root1 || !root2 || root1->val != root2->val)
            return false;

        // no flip OR flip
        return 
            (flipEquiv(root1->left, root2->left) &&
             flipEquiv(root1->right, root2->right)) ||
            (flipEquiv(root1->left, root2->right) &&
             flipEquiv(root1->right, root2->left));
    }
};
