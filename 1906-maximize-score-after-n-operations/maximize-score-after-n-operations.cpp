class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int totalMasks = 1 << m;

        vector<int> dp(totalMasks, 0);

        for (int mask = 0; mask < totalMasks; mask++) {

            int used = __builtin_popcount(mask);

            // We always select elements in pairs
            if (used % 2 != 0)
                continue;

            int operation = used / 2 + 1;

            for (int i = 0; i < m; i++) {

                if (mask & (1 << i))
                    continue;

                for (int j = i + 1; j < m; j++) {

                    if (mask & (1 << j))
                        continue;

                    int newMask = mask | (1 << i) | (1 << j);

                    int score =
                        operation * gcd(nums[i], nums[j]);

                    dp[newMask] = max(
                        dp[newMask],
                        dp[mask] + score
                    );
                }
            }
        }

        return dp[totalMasks - 1];
    }
};