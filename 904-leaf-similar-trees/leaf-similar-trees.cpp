class Solution {
public:
    void collectLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;

        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }

        collectLeaves(root->left, leaves);
        collectLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }
};
