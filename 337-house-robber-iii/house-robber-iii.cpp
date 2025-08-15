// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second); // max of robbing or skipping root
    }
private:
    // returns {take, skip} for this node
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto L = dfs(node->left);
        auto R = dfs(node->right);

        int take = node->val + L.second + R.second;                  // if rob this node, must skip children
        int skip = max(L.first, L.second) + max(R.first, R.second);  // else take best of children

        return {take, skip};
    }
};
