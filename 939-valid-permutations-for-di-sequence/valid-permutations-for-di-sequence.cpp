class Solution {
public:
    int numPermsDISequence(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> prefix(i + 1, 0);
            prefix[0] = dp[i - 1][0];

            for (int j = 1; j < i; j++) {
                prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % MOD;
            }

            for (int j = 0; j <= i; j++) {
                if (s[i - 1] == 'I') {
                    dp[i][j] = (j == 0 ? 0 : prefix[j - 1]);
                } else {
                    dp[i][j] = (prefix[i - 1] - (j == 0 ? 0 : prefix[j - 1]) + MOD) % MOD;
                }
            }
        }

        int ans = 0;
        for (int j = 0; j <= n; j++) {
            ans = (ans + dp[n][j]) % MOD;
        }
        return ans;
    }
};
