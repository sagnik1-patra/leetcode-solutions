
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();
        const int INF = 1e9;

        // dp[t][i] = minimum cost to reach city i
        // using exactly t minutes
        vector<vector<int>> dp(
            maxTime + 1, vector<int>(n, INF)
        );

        dp[0][0] = passingFees[0];

        for (int t = 1; t <= maxTime; t++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int time = edge[2];

                if (t >= time) {
                    if (dp[t - time][u] != INF) {
                        dp[t][v] = min(
                            dp[t][v],
                            dp[t - time][u] + passingFees[v]
                        );
                    }

                    if (dp[t - time][v] != INF) {
                        dp[t][u] = min(
                            dp[t][u],
                            dp[t - time][v] + passingFees[u]
                        );
                    }
                }
            }
        }

        int ans = INF;

        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t][n - 1]);
        }

        return ans == INF ? -1 : ans;
    }
};
