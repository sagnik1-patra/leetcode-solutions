class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        // dp[i][a][l]
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, 0)));

        dp[0][0][0] = 1; // empty record

        for (int i = 1; i <= n; i++) {
            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {
                    long long val = dp[i-1][a][l];
                    if (val == 0) continue;

                    // add 'P'
                    dp[i][a][0] = (dp[i][a][0] + val) % MOD;

                    // add 'A'
                    if (a < 1) {
                        dp[i][a+1][0] = (dp[i][a+1][0] + val) % MOD;
                    }

                    // add 'L'
                    if (l < 2) {
                        dp[i][a][l+1] = (dp[i][a][l+1] + val) % MOD;
                    }
                }
            }
        }

        long long ans = 0;
        for (int a = 0; a <= 1; a++) {
            for (int l = 0; l <= 2; l++) {
                ans = (ans + dp[n][a][l]) % MOD;
            }
        }

        return ans;
    }
};
