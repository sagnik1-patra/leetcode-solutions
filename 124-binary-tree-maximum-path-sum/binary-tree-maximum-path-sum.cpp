class Solution {
public:
    int maxSum;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Recursively compute max gain from left and right subtrees
        int leftGain = max(maxGain(node->left), 0);  // ignore paths with negative sum
        int rightGain = max(maxGain(node->right), 0);

        // Check the price of the path going through the current node
        int currentPathSum = node->val + leftGain + rightGain;

        // Update global maximum path sum
        maxSum = max(maxSum, currentPathSum);

        // Return the max gain the node and one of its subtrees can add to the path
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
};
