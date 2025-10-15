/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, vector<vector<string>>& res, int r, int c, int height) {
        if (!root) return;
        res[r][c] = to_string(root->val);

        // Only compute offset if we’re not at the last level
        if (r < height) {
            int offset = 1 << (height - r - 1);  // 2^(height - r - 1)
            if (root->left)  fill(root->left, res, r + 1, c - offset, height);
            if (root->right) fill(root->right, res, r + 1, c + offset, height);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;  // total columns = 2^(height+1) - 1

        vector<vector<string>> res(m, vector<string>(n, ""));
        fill(root, res, 0, (n - 1) / 2, height);
        return res;
    }
};
