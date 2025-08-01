class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Update grid in place with the min path sum to each cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; // start cell
                else if (i == 0) grid[i][j] += grid[i][j - 1]; // first row
                else if (j == 0) grid[i][j] += grid[i - 1][j]; // first column
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); // min of top or left
            }
        }

        return grid[m - 1][n - 1];
    }
};
