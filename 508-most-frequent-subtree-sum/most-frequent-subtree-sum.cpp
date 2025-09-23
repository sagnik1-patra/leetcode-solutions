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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> freq;  // sum -> count
        int best = 0;
        dfs(root, freq, best);

        vector<int> ans;
        ans.reserve(freq.size());
        for (auto &p : freq) if (p.second == best) ans.push_back(p.first);
        return ans;
    }

private:
    int dfs(TreeNode* node, unordered_map<int,int>& freq, int& best) {
        if (!node) return 0;
        int left = dfs(node->left, freq, best);
        int right = dfs(node->right, freq, best);
        long long sumLL = (long long)left + right + node->val; // guard overflow in intermediate
        int sum = (int)sumLL;
        int c = ++freq[sum];
        if (c > best) best = c;
        return sum;
    }
};
