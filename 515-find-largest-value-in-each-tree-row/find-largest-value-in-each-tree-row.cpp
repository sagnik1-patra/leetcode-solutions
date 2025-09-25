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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = (int)q.size();
            long long levelMax = LLONG_MIN;  // handle full int range
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                levelMax = std::max(levelMax, (long long)node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back((int)levelMax);
        }
        return ans;
    }
};
