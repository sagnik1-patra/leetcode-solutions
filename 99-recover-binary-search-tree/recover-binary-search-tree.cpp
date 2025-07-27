class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;
        TreeNode* predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // Find the rightmost node in left subtree or link back to root
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // Create a temporary thread to root
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // Visit the root
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) x = pred;
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                // Visit the root
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) x = pred;
                }
                pred = root;

                root = root->right;
            }
        }

        // Swap the values of the two nodes
        if (x != nullptr && y != nullptr) {
            std::swap(x->val, y->val);
        }
    }
};
