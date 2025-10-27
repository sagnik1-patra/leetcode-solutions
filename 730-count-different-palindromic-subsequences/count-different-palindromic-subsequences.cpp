class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;

                if (s[i] != s[j]) {
                    dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % MOD - dp[i + 1][j - 1] + MOD) % MOD;
                } else {
                    int l = i + 1, r = j - 1;
                    while (l <= r && s[l] != s[i]) ++l;
                    while (l <= r && s[r] != s[i]) --r;

                    if (l > r) {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                    } else if (l == r) {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                    } else {
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % MOD - dp[l + 1][r - 1] + MOD) % MOD;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
