class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(k + 1), new_dp(k + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            new_dp[0] = 1;
            for (int j = 1; j <= k; ++j) {
                long val = (dp[j] + new_dp[j - 1]) % MOD;
                if (j >= i) val = (val - dp[j - i] + MOD) % MOD;
                new_dp[j] = val;
            }
            dp.swap(new_dp);
            fill(new_dp.begin(), new_dp.end(), 0);
        }
        return dp[k];
    }
};
