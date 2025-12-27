class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int r : rods) {
            auto cur = dp; // snapshot
            for (auto [d, h] : cur) {
                // Put rod on taller side
                dp[d + r] = max(dp[d + r], h);

                // Put rod on shorter side
                int newDiff = abs(d - r);
                int newHeight = h + min(d, r);
                dp[newDiff] = max(dp[newDiff], newHeight);
            }
        }

        return dp[0];
    }
};
