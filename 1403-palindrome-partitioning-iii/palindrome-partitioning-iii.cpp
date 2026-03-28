class Solution {
public:
    int palindromePartition(string s, int K) {
        int n = s.size();

        // Step 1: Precompute cost
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    cost[i][j] = cost[i+1][j-1];
                } else {
                    cost[i][j] = cost[i+1][j-1] + 1;
                }
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= K; k++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j][k-1] != INT_MAX) {
                        dp[i][k] = min(dp[i][k],
                                       dp[j][k-1] + cost[j][i-1]);
                    }
                }
            }
        }

        return dp[n][K];
    }
};