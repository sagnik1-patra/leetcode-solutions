class Solution {
public:
    string ans = "";

    void dfs(TreeNode* root, string& path) {
        if (!root) return;

        // Add current character
        path.push_back('a' + root->val);

        // If leaf node
        if (!root->left && !root->right) {
            string leafToRoot = path;
            reverse(leafToRoot.begin(), leafToRoot.end());

            if (ans.empty() || leafToRoot < ans) {
                ans = leafToRoot;
            }
        }

        // Continue DFS
        dfs(root->left, path);
        dfs(root->right, path);

        // Backtrack
        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return ans;
    }
};
