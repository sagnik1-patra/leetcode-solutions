class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode* node, int &ans) {
        if (!node) return 0;
        
        int left = dfs(node->left, ans);
        int right = dfs(node->right, ans);
        
        int leftPath = 0, rightPath = 0;
        
        if (node->left && node->left->val == node->val)
            leftPath = left + 1;
        if (node->right && node->right->val == node->val)
            rightPath = right + 1;
        
        // Update global answer (max of left + right)
        ans = max(ans, leftPath + rightPath);
        
        // Return max path extending downward
        return max(leftPath, rightPath);
    }
};