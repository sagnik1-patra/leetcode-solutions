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
    string tree2str(TreeNode* root) {
        if (!root) return "";

        string res = to_string(root->val);

        // Case 1: No children → return just the node value
        if (!root->left && !root->right)
            return res;

        // Case 2: Has left child → include left part
        // If no left child but has right → add "()"
        res += "(" + tree2str(root->left) + ")";

        // Case 3: Has right child → include right part
        if (root->right)
            res += "(" + tree2str(root->right) + ")";

        return res;
    }
};
