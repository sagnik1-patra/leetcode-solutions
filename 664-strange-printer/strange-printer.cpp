class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;

        // dp[i][j] = min turns to print substring s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: single character needs 1 turn
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        // Build from shorter substrings to longer
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j] + 1;  // worst case: print s[i] separately

                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] == s[i]) {
                        // s[i] can merge with s[k]
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
