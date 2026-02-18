class Solution {
public:
    int leftCount = 0, rightCount = 0;

    int count(TreeNode* root, int x) {
        if (!root) return 0;

        int l = count(root->left, x);
        int r = count(root->right, x);

        if (root->val == x) {
            leftCount = l;
            rightCount = r;
        }

        return l + r + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);

        int parent = n - (leftCount + rightCount + 1);

        int half = n / 2;

        return max({leftCount, rightCount, parent}) > half;
    }
};
