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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        // Find index of maximum element
        int maxIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);

        // Recursively build left and right subtrees
        root->left = build(nums, left, maxIndex);
        root->right = build(nums, maxIndex + 1, right);

        return root;
    }
};
