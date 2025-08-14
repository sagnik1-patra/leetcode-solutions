class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1; // upper bound (since min coin is 1 at best)
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (c <= a && dp[a - c] != INF) {
                    dp[a] = min(dp[a], dp[a - c] + 1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
