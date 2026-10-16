
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int maxi = 0, sum = 0;

            for (int j = i; j < n; j++) {
                maxi = max(maxi, nums[j]);
                sum += nums[j];

                cost[i][j] = maxi * (j - i + 1) - sum;
            }
        }

        vector<vector<int>> dp(k + 2, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int resize = 1; resize <= k + 1; resize++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[resize - 1][j] == INF) {
                        continue;
                    }

                    dp[resize][i] = min(
                        dp[resize][i],
                        dp[resize - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k + 1][n];
    }
};
