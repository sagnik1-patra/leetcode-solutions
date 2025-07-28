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
    unordered_map<int, int> inorderIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inorderIndex[rootVal];
        int leftSize = inRoot - inStart;

        root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                     postorder, postStart, postStart + leftSize - 1);

        root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                      postorder, postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1);
    }
};
