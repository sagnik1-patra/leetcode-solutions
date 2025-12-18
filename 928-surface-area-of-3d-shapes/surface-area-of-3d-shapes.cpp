class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int surface = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];
                if (h == 0) continue;

                // Total faces of h cubes
                surface += 6 * h;

                // Internal vertical faces
                surface -= 2 * (h - 1);

                // Shared faces with neighbors
                if (i > 0)
                    surface -= 2 * min(h, grid[i - 1][j]);
                if (j > 0)
                    surface -= 2 * min(h, grid[i][j - 1]);
            }
        }

        return surface;
    }
};
