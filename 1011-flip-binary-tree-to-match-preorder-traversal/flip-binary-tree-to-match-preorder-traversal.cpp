class Solution {
public:
    vector<int> result;
    int idx = 0;

    bool dfs(TreeNode* root, vector<int>& voyage) {
        if (!root) return true;

        // Current node must match voyage
        if (root->val != voyage[idx]) {
            return false;
        }
        idx++;

        // If left child exists and doesn't match next voyage value,
        // but right child does, then we must flip
        if (root->left && idx < voyage.size() &&
            root->left->val != voyage[idx]) {

            // Check if flipping helps
            if (root->right && root->right->val == voyage[idx]) {
                result.push_back(root->val);
                // Flip: traverse right first, then left
                return dfs(root->right, voyage) &&
                       dfs(root->left, voyage);
            } else {
                return false;
            }
        }

        // Normal preorder: left then right
        return dfs(root->left, voyage) &&
               dfs(root->right, voyage);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (!dfs(root, voyage)) {
            return {-1};
        }
        return result;
    }
};
