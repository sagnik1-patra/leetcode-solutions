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
    unordered_map<string, int> freq;
    vector<TreeNode*> result;

    string serialize(TreeNode* root) {
        if (!root) return "#";

        string serial = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);

        // Count each serialized subtree
        if (++freq[serial] == 2)  // only add once
            result.push_back(root);

        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};
