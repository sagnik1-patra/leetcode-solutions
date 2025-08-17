class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1);        // dp[i] = length of best subset ending at i
        vector<int> parent(n, -1);   // parent for path reconstruction

        int bestLen = 1, bestIdx = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > bestLen) {
                bestLen = dp[i];
                bestIdx = i;
            }
        }

        // Reconstruct subset
        vector<int> ans;
        for (int i = bestIdx; i != -1; i = parent[i]) {
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
