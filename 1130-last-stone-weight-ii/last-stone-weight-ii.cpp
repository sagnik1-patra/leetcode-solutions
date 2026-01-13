class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int w : stones) total += w;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int w : stones) {
            for (int s = target; s >= w; s--) {
                dp[s] = dp[s] || dp[s - w];
            }
        }

        for (int s = target; s >= 0; s--) {
            if (dp[s]) {
                return total - 2 * s;
            }
        }

        return 0;
    }
};
