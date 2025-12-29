class Solution {
public:
    int cameras = 0;

    // Returns state:
    // 0 = needs camera
    // 1 = has camera
    // 2 = covered
    int dfs(TreeNode* root) {
        if (!root) return 2; // null nodes are covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If any child needs a camera, place camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has a camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Otherwise, this node needs a camera
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            cameras++; // root needs a camera
        }
        return cameras;
    }
};
