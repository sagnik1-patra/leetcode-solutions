class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<int>> dp = grid;

        // Count normal pyramids
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 1 + min({
                        dp[i + 1][j - 1],
                        dp[i + 1][j],
                        dp[i + 1][j + 1]
                    });

                    ans += dp[i][j] - 1;
                }
            }
        }

        // Reset DP
        dp = grid;

        // Count inverse pyramids
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j + 1]
                    });

                    ans += dp[i][j] - 1;
                }
            }
        }

        return ans;
    }
};