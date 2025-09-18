// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        // 1) First Morris inorder: compute maxCount
        long long prevVal = 0;
        bool hasPrev = false;
        int currCount = 0, maxCount = 0;

        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                // visit cur
                update(cur->val, hasPrev, prevVal, currCount, maxCount, nullptr);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;
                if (!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    // visit cur
                    update(cur->val, hasPrev, prevVal, currCount, maxCount, nullptr);
                    cur = cur->right;
                }
            }
        }

        // 2) Second Morris inorder: collect values with count == maxCount
        vector<int> modes;
        prevVal = 0; hasPrev = false; currCount = 0;
        cur = root;
        while (cur) {
            if (!cur->left) {
                update(cur->val, hasPrev, prevVal, currCount, maxCount, &modes);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;
                if (!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    update(cur->val, hasPrev, prevVal, currCount, maxCount, &modes);
                    cur = cur->right;
                }
            }
        }
        return modes;
    }

private:
    // If 'out' is nullptr: only update maxCount.
    // If 'out' is not nullptr: collect values equal to maxCount.
    static void update(int val, bool& hasPrev, long long& prevVal,
                       int& currCount, int& maxCount, vector<int>* out) {
        if (!hasPrev || val != prevVal) {
            prevVal = val;
            currCount = 1;
            hasPrev = true;
        } else {
            ++currCount;
        }

        if (!out) {
            if (currCount > maxCount) maxCount = currCount;
        } else {
            if (currCount == maxCount) out->push_back(val);
        }
    }
};
