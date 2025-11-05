class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;

        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        // dp[i] = number of ways to tile 2 x i board
        vector<long long> dp(n + 1, 0);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        // Recurrence:
        // dp[i] = 2 * dp[i - 1] + dp[i - 3]
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};