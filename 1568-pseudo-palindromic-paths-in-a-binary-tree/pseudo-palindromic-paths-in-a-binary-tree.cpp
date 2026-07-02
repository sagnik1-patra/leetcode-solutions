class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, int mask) {
        if (root == NULL) return;

        // toggle bit for root->val
        mask ^= (1 << root->val);

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            // check if mask has at most one set bit
            if ((mask & (mask - 1)) == 0) {
                count++;
            }
            return;
        }

        dfs(root->left, mask);
        dfs(root->right, mask);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root, 0);
        return count;
    }
};