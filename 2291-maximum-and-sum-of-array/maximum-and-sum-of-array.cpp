
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int total = 2 * numSlots;

        vector<int> dp(1 << total, -1);
        dp[0] = 0;

        int ans = 0;

        for (int mask = 0; mask < (1 << total); mask++) {
            if (dp[mask] == -1)
                continue;

            int idx = __builtin_popcount((unsigned)mask);

            if (idx == n) {
                ans = max(ans, dp[mask]);
                continue;
            }

            for (int j = 0; j < total; j++) {
                if ((mask & (1 << j)) == 0) {
                    int slot = j / 2 + 1;

                    int newMask = mask | (1 << j);

                    dp[newMask] = max(
                        dp[newMask],
                        dp[mask] + (nums[idx] & slot)
                    );
                }
            }
        }

        return ans;
    }
};
