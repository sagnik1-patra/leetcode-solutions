class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {
        // Full binary trees require odd number of nodes
        if (n % 2 == 0) return {};

        if (n == 1) {
            return { new TreeNode(0) };
        }

        if (memo.count(n)) return memo[n];

        vector<TreeNode*> res;

        // Split nodes between left and right subtrees
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;

            auto leftTrees = allPossibleFBT(left);
            auto rightTrees = allPossibleFBT(right);

            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        memo[n] = res;
        return res;
    }
};
