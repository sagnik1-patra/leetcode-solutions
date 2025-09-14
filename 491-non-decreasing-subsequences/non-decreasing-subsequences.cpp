class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(0, INT_MIN, nums, cur, ans);
        return ans;
    }

private:
    void dfs(int idx, int last, const vector<int>& nums,
             vector<int>& cur, vector<vector<int>>& ans) {
        if (idx == (int)nums.size()) return;

        bool used[201] = {false}; // values in [-100,100] -> shift by +100

        for (int i = idx; i < (int)nums.size(); ++i) {
            int x = nums[i];
            if (x < last) continue;                // keep non-decreasing
            int key = x + 100;
            if (used[key]) continue;               // avoid duplicates at this depth
            used[key] = true;

            cur.push_back(x);
            if ((int)cur.size() >= 2) ans.push_back(cur); // record prefix subsequence
            dfs(i + 1, x, nums, cur, ans);                // extend further
            cur.pop_back();
        }
    }
};