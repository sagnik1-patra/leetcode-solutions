class Solution {
public:
    int m, n;
    int originalColor;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<bool>> visited;
    vector<pair<int,int>> borders;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        visited[r][c] = true;
        bool isBorder = false;

        for (auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];

            // Out of bounds → border
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                isBorder = true;
            }
            // Different color neighbor → border
            else if (grid[nr][nc] != originalColor) {
                isBorder = true;
            }
            // Same color and not visited → DFS
            else if (!visited[nr][nc]) {
                dfs(nr, nc, grid);
            }
        }

        if (isBorder) {
            borders.push_back({r, c});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        originalColor = grid[row][col];

        visited.assign(m, vector<bool>(n, false));

        dfs(row, col, grid);

        for (auto& p : borders) {
            grid[p.first][p.second] = color;
        }

        return grid;
    }
};
