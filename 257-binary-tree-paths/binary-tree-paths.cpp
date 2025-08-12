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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        dfs(root, "", paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;

        // Append current node's value to the path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        // If it's a leaf, add to result
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }

        // Recursive DFS calls
        if (node->left) dfs(node->left, path, paths);
        if (node->right) dfs(node->right, path, paths);
    }
};
