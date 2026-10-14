
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> elements;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // Top row: left to right
            for (int j = left; j <= right; j++)
                elements.push_back(grid[top][j]);

            // Right column: top to bottom
            for (int i = top + 1; i <= bottom; i++)
                elements.push_back(grid[i][right]);

            // Bottom row: right to left
            for (int j = right - 1; j >= left; j--)
                elements.push_back(grid[bottom][j]);

            // Left column: bottom to top
            for (int i = bottom - 1; i > top; i--)
                elements.push_back(grid[i][left]);

            int len = elements.size();
            int shift = k % len;
            int idx = 0;

            // Write rotated top row
            for (int j = left; j <= right; j++)
                grid[top][j] = elements[(idx++ + shift) % len];

            // Write rotated right column
            for (int i = top + 1; i <= bottom; i++)
                grid[i][right] = elements[(idx++ + shift) % len];

            // Write rotated bottom row
            for (int j = right - 1; j >= left; j--)
                grid[bottom][j] = elements[(idx++ + shift) % len];

            // Write rotated left column
            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = elements[(idx++ + shift) % len];
        }

        return grid;
    }
};
