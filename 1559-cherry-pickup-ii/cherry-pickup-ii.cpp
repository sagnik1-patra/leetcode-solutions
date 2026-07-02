class Solution {
public:
    int rows, cols;
    int dp[70][70][70];

    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        if (c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols) {
            return -1e9;
        }

        if (row == rows) {
            return 0;
        }

        if (dp[row][c1][c2] != -1) {
            return dp[row][c1][c2];
        }

        int cherries = grid[row][c1];

        if (c1 != c2) {
            cherries += grid[row][c2];
        }

        int best = 0;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                best = max(best, solve(grid, row + 1, c1 + d1, c2 + d2));
            }
        }

        return dp[row][c1][c2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, cols - 1);
    }
};