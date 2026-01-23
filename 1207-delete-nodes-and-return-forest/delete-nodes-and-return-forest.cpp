class Solution {
public:
    vector<TreeNode*> result;
    unordered_set<int> del;

    TreeNode* dfs(TreeNode* node, bool isRoot) {
        if (!node) return nullptr;

        bool deleted = del.count(node->val);

        if (isRoot && !deleted) {
            result.push_back(node);
        }

        node->left = dfs(node->left, deleted);
        node->right = dfs(node->right, deleted);

        return deleted ? nullptr : node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        del = unordered_set<int>(to_delete.begin(), to_delete.end());
        dfs(root, true);
        return result;
    }
};
