class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];

        for (int r1 = 0; r1 < n; ++r1) {
            for (int c1 = 0; c1 < n; ++c1) {
                for (int r2 = 0; r2 < n; ++r2) {
                    int c2 = r1 + c1 - r2;
                    if (c2 < 0 || c2 >= n) continue;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    int bestPrev = INT_MIN;
                    if (r1 > 0 && r2 > 0) bestPrev = max(bestPrev, dp[r1 - 1][c1][r2 - 1]);
                    if (r1 > 0 && c2 > 0) bestPrev = max(bestPrev, dp[r1 - 1][c1][r2]);
                    if (c1 > 0 && r2 > 0) bestPrev = max(bestPrev, dp[r1][c1 - 1][r2 - 1]);
                    if (c1 > 0 && c2 > 0) bestPrev = max(bestPrev, dp[r1][c1 - 1][r2]);

                    if (r1 == 0 && c1 == 0 && r2 == 0) bestPrev = 0;
                    if (bestPrev < 0) continue; // no valid path

                    int cherries = grid[r1][c1];
                    if (r1 != r2) cherries += grid[r2][c2];
                    dp[r1][c1][r2] = bestPrev + cherries;
                }
            }
        }

        return max(0, dp[n - 1][n - 1][n - 1]);
    }
};
