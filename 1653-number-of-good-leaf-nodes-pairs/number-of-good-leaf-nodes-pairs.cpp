class Solution {
public:
    int result = 0;
    
    vector<int> dfs(TreeNode* root, int distance) {
        if (!root) return {};
        
        // leaf node
        if (!root->left && !root->right) {
            return {1};
        }
        
        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);
        
        // count pairs
        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }
        
        // return distances to parent
        vector<int> curr;
        
        for (int d : left) {
            if (d + 1 < distance) curr.push_back(d + 1);
        }
        
        for (int d : right) {
            if (d + 1 < distance) curr.push_back(d + 1);
        }
        
        return curr;
    }
    
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return result;
    }
};