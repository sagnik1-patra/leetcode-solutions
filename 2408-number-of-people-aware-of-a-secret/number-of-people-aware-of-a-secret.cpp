class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);

        dp[1] = 1;

        long long sharing = 0;

        for (int i = 2; i <= n; i++) {

            // People who start sharing today
            if (i - delay >= 1) {
                sharing = (sharing + dp[i - delay]) % MOD;
            }

            // People who forget today
            if (i - forget >= 1) {
                sharing = (sharing - dp[i - forget] + MOD) % MOD;
            }

            // New people discovering the secret today
            dp[i] = sharing;
        }

        long long ans = 0;

        // Count people who still remember the secret
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};