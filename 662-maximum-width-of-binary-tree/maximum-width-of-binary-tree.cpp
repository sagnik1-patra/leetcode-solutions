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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;  // node + index
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long left = q.front().second;  // index of first node in level
            long long right = left;             // index of last node in level

            for (int i = 0; i < size; ++i) {
                auto [node, index] = q.front();
                q.pop();
                right = index;

                // Normalize indices to prevent overflow
                long long norm = index - left;

                if (node->left) q.push({node->left, 2 * norm + 1});
                if (node->right) q.push({node->right, 2 * norm + 2});
            }

            maxWidth = max(maxWidth, right - left + 1);
        }

        return (int)maxWidth;
    }
};
