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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, val, 1, depth);
        return root;
    }

    void dfs(TreeNode* node, int val, int curDepth, int targetDepth) {
        if (!node) return;
        if (curDepth == targetDepth - 1) {
            TreeNode* tempL = node->left;
            TreeNode* tempR = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = tempL;
            node->right->right = tempR;
        } else {
            dfs(node->left, val, curDepth + 1, targetDepth);
            dfs(node->right, val, curDepth + 1, targetDepth);
        }
    }
};
