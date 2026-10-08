
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int total = 1 << n;

        vector<int> dp(total, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < total; mask++) {
            if (dp[mask] == INT_MAX)
                continue;

            int i = __builtin_popcount((unsigned int)mask);

            if (i == n)
                continue;

            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    int newMask = mask | (1 << j);

                    dp[newMask] = min(
                        dp[newMask],
                        dp[mask] + (nums1[i] ^ nums2[j])
                    );
                }
            }
        }

        return dp[total - 1];
    }
};
