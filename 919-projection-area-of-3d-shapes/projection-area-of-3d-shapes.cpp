class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int top = 0, front = 0, side = 0;

        // Top projection
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0)
                    top++;
            }
        }

        // Front projection (row-wise max)
        for (int i = 0; i < n; i++) {
            int rowMax = 0;
            for (int j = 0; j < n; j++) {
                rowMax = max(rowMax, grid[i][j]);
            }
            front += rowMax;
        }

        // Side projection (column-wise max)
        for (int j = 0; j < n; j++) {
            int colMax = 0;
            for (int i = 0; i < n; i++) {
                colMax = max(colMax, grid[i][j]);
            }
            side += colMax;
        }

        return top + front + side;
    }
};
