class Solution {
public:
    static const int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        int crimes = group.size();

        // dp[m][p] = number of ways
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < crimes; i++) {
            int g = group[i];
            int pr = profit[i];

            for (int m = n; m >= g; m--) {
                for (int p = minProfit; p >= 0; p--) {
                    int newProfit = min(minProfit, p + pr);
                    dp[m][newProfit] =
                        (dp[m][newProfit] + dp[m - g][p]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int m = 0; m <= n; m++) {
            ans = (ans + dp[m][minProfit]) % MOD;
        }

        return ans;
    }
};
