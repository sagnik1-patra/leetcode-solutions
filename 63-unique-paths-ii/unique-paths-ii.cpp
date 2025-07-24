class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();        // number of rows
        int n = obstacleGrid[0].size();     // number of columns

        vector<vector<int>> dp(m, vector<int>(n, 0)); // DP table

        // If the starting cell has an obstacle, return 0
        if (obstacleGrid[0][0] == 1) return 0;

        dp[0][0] = 1; // Starting point

        // Fill the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1)
                dp[i][0] = 1;
        }

        // Fill the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1)
                dp[0][j] = 1;
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
