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
    int findBottomLeftValue(TreeNode* root) {
        // Level-order traversal; record the first node of each level
        std::queue<TreeNode*> q;
        q.push(root);
        int leftmost = root->val;

        while (!q.empty()) {
            int sz = (int)q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (i == 0) leftmost = node->val; // first node in this level

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return leftmost;
    }
};
