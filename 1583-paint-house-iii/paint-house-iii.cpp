class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9;

        // dp[i][prevColor][neighborhoods]
        vector<vector<vector<int>>> dp(
            m + 1,
            vector<vector<int>>(n + 1, vector<int>(target + 1, INF))
        );

        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int prevColor = 0; prevColor <= n; prevColor++) {
                for (int groups = 0; groups <= target; groups++) {
                    if (dp[i][prevColor][groups] == INF) continue;

                    // If house is already painted
                    if (houses[i] != 0) {
                        int color = houses[i];
                        int newGroups = groups + (color != prevColor);

                        if (newGroups <= target) {
                            dp[i + 1][color][newGroups] =
                                min(dp[i + 1][color][newGroups],
                                    dp[i][prevColor][groups]);
                        }
                    }

                    // If house is not painted
                    else {
                        for (int color = 1; color <= n; color++) {
                            int newGroups = groups + (color != prevColor);
                            int paintCost = cost[i][color - 1];

                            if (newGroups <= target) {
                                dp[i + 1][color][newGroups] =
                                    min(dp[i + 1][color][newGroups],
                                        dp[i][prevColor][groups] + paintCost);
                            }
                        }
                    }
                }
            }
        }

        int ans = INF;

        for (int color = 1; color <= n; color++) {
            ans = min(ans, dp[m][color][target]);
        }

        return ans == INF ? -1 : ans;
    }
};