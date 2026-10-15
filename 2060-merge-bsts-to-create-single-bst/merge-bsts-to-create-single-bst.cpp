
class Solution {
public:
    unordered_map<int, TreeNode*> mp;
    int merged = 0;

    bool dfs(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        // Check BST property
        if (node->val <= low || node->val >= high)
            return false;

        // Merge if current node is a leaf
        if (!node->left && !node->right &&
            mp.count(node->val)) {

            TreeNode* root = mp[node->val];

            if (root != node) {
                node->left = root->left;
                node->right = root->right;

                mp.erase(node->val);
                merged++;
            }
        }

        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        mp.clear();
        merged = 0;

        unordered_set<int> leaves;

        // Store all roots
        for (auto root : trees) {
            mp[root->val] = root;
        }

        // Store all leaf values
        for (auto root : trees) {
            if (root->left)
                leaves.insert(root->left->val);

            if (root->right)
                leaves.insert(root->right->val);
        }

        // Find the final root
        TreeNode* root = nullptr;

        for (auto tree : trees) {
            if (!leaves.count(tree->val)) {
                if (root != nullptr)
                    return nullptr;

                root = tree;
            }
        }

        if (!root) return nullptr;

        // Remove final root from merge candidates
        mp.erase(root->val);

        // Merge and validate BST
        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return nullptr;

        // Every other BST must be merged
        if (!mp.empty())
            return nullptr;

        return root;
    }
};
