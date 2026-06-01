class Solution {
public:
    long long total = 0;
    long long maxProductVal = 0;
    const int MOD = 1e9 + 7;
    
    // Step 1: compute total sum
    long long getTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }
    
    // Step 2: compute subtree sums and max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;
        
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        
        long long sub = root->val + left + right;
        
        // try cutting here
        maxProductVal = max(maxProductVal, sub * (total - sub));
        
        return sub;
    }
    
    int maxProduct(TreeNode* root) {
        total = getTotal(root);
        dfs(root);
        
        return maxProductVal % MOD;
    }
};