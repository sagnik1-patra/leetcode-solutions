class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        // length from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int l = 1; l + len - 1 <= n; ++l) {
                int r = l + len - 1;
                dp[l][r] = INT_MAX;
                for (int x = l; x <= r; ++x) {
                    int cost = x + max((x-1 >= l ? dp[l][x-1] : 0),
                                       (x+1 <= r ? dp[x+1][r] : 0));
                    dp[l][r] = min(dp[l][r], cost);
                }
            }
        }
        return dp[1][n];
    }
};
