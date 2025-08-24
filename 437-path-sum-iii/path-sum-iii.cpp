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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        long long ans = 0;
        dfs(root, 0LL, targetSum, mp, ans);
        return (int)ans;
    }

private:
    void dfs(TreeNode* node, long long pref, long long target,
             unordered_map<long long,int>& mp, long long& ans) {
        if (!node) return;
        pref += node->val;
        if (mp.count(pref - target)) ans += mp[pref - target];

        mp[pref]++;
        dfs(node->left, pref, target, mp, ans);
        dfs(node->right, pref, target, mp, ans);
        if (--mp[pref] == 0) mp.erase(pref); // backtrack
    }
};
