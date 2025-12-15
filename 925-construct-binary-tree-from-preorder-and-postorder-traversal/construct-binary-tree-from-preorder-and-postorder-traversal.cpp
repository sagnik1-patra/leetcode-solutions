class Solution {
public:
    unordered_map<int, int> postIndex;

    TreeNode* build(
        vector<int>& preorder, int preL, int preR,
        vector<int>& postorder, int postL, int postR
    ) {
        if (preL > preR) return nullptr;

        TreeNode* root = new TreeNode(preorder[preL]);

        // Leaf node
        if (preL == preR) return root;

        // Root of left subtree
        int leftRootVal = preorder[preL + 1];
        int idx = postIndex[leftRootVal];

        int leftSize = idx - postL + 1;

        root->left = build(
            preorder, preL + 1, preL + leftSize,
            postorder, postL, idx
        );

        root->right = build(
            preorder, preL + leftSize + 1, preR,
            postorder, idx + 1, postR - 1
        );

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }

        return build(
            preorder, 0, preorder.size() - 1,
            postorder, 0, postorder.size() - 1
        );
    }
};
