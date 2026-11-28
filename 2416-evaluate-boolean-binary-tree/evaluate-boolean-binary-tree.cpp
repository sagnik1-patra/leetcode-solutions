class Solution {
public:
    bool evaluateTree(TreeNode* root) {

        // Base case: Leaf node
        if (root->left == NULL && root->right == NULL) {
            return root->val == 1;
        }

        // Evaluate both subtrees
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        // OR operation
        if (root->val == 2) {
            return left || right;
        }

        // AND operation
        return left && right;
    }
};