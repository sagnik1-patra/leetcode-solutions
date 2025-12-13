class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Ensure first column is all 1s
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        // Step 2: Flip columns to maximize 1s
        for (int j = 1; j < n; j++) {
            int ones = 0;
            for (int i = 0; i < m; i++) {
                ones += grid[i][j];
            }
            if (ones < m - ones) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        // Step 3: Calculate score
        int score = 0;
        for (int i = 0; i < m; i++) {
            int value = 0;
            for (int j = 0; j < n; j++) {
                value = (value << 1) | grid[i][j];
            }
            score += value;
        }

        return score;
    }
};
