class Solution {
public:
    int solve(TreeNode* node, int parent, int grandparent) {
        if (!node) return 0;
        
        int sum = 0;
        
        // If grandparent is even → include this node
        if (grandparent % 2 == 0) {
            sum += node->val;
        }
        
        // Recurse left & right
        sum += solve(node->left, node->val, parent);
        sum += solve(node->right, node->val, parent);
        
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, 1, 1); // start with odd values
    }
};