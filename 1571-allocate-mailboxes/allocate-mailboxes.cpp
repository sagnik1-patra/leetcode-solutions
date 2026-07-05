class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        int n = houses.size();
        const int INF = 1e9;

        // cost[i][j] = min cost to cover houses i to j with 1 mailbox
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mid = (i + j) / 2;

                for (int x = i; x <= j; x++) {
                    cost[i][j] += abs(houses[x] - houses[mid]);
                }
            }
        }

        // dp[i][mailbox] = min cost to cover first i houses using mailbox mailboxes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int mailbox = 1; mailbox <= k; mailbox++) {
                for (int prev = 0; prev < i; prev++) {
                    if (dp[prev][mailbox - 1] != INF) {
                        dp[i][mailbox] = min(
                            dp[i][mailbox],
                            dp[prev][mailbox - 1] + cost[prev][i - 1]
                        );
                    }
                }
            }
        }

        return dp[n][k];
    }
};