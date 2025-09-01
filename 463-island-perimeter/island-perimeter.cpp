class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int perim = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 0) continue;
                perim += 4;
                if (i > 0 && grid[i-1][j] == 1) perim -= 2; // shared with top
                if (j > 0 && grid[i][j-1] == 1) perim -= 2; // shared with left
            }
        }
        return perim;
    }
};
