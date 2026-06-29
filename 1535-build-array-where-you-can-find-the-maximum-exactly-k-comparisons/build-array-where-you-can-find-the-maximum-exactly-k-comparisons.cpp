class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0))
        );

        for (int maxVal = 1; maxVal <= m; maxVal++) {
            dp[1][maxVal][1] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int maxVal = 1; maxVal <= m; maxVal++) {
                for (int cost = 1; cost <= k; cost++) {
                    
                    dp[len][maxVal][cost] += dp[len - 1][maxVal][cost] * maxVal;
                    dp[len][maxVal][cost] %= MOD;

                    for (int prevMax = 1; prevMax < maxVal; prevMax++) {
                        dp[len][maxVal][cost] += dp[len - 1][prevMax][cost - 1];
                        dp[len][maxVal][cost] %= MOD;
                    }
                }
            }
        }

        long long ans = 0;

        for (int maxVal = 1; maxVal <= m; maxVal++) {
            ans = (ans + dp[n][maxVal][k]) % MOD;
        }

        return ans;
    }
};