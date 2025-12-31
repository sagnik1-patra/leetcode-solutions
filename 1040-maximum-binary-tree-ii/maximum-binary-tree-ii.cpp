class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // Case 1: val becomes new root
        if (!root || val > root->val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        // Case 2: insert into right subtree
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
