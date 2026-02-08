class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // Precompute right and down arrays
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = 1 + (j + 1 < n ? right[i][j + 1] : 0);
                    down[i][j] = 1 + (i + 1 < m ? down[i + 1][j] : 0);
                }
            }
        }

        int maxSize = 0;

        // Try all top-left corners
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxPossible = min(right[i][j], down[i][j]);
                for (int size = maxPossible; size > maxSize; size--) {
                    if (right[i + size - 1][j] >= size &&
                        down[i][j + size - 1] >= size) {
                        maxSize = size;
                        break;
                    }
                }
            }
        }

        return maxSize * maxSize;
    }
};
