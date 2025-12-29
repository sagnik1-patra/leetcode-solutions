class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> travel(366, false);
        for (int d : days) {
            travel[d] = true;
        }

        vector<int> dp(366, 0);

        for (int d = 1; d <= 365; d++) {
            if (!travel[d]) {
                dp[d] = dp[d - 1];
            } else {
                dp[d] = min({
                    dp[d - 1] + costs[0],
                    dp[max(0, d - 7)] + costs[1],
                    dp[max(0, d - 30)] + costs[2]
                });
            }
        }

        return dp[365];
    }
};
