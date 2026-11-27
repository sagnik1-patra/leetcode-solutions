class Solution {
public:
    int minPathCost(vector<vector<int>>& grid,
                    vector<vector<int>>& moveCost) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        // Initialize the first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

        // Calculate minimum cost for remaining rows
        for (int i = 1; i < m; i++) {

            for (int j = 0; j < n; j++) {

                for (int k = 0; k < n; k++) {

                    int cost = dp[i-1][k]
                             + moveCost[grid[i-1][k]][j]
                             + grid[i][j];

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};