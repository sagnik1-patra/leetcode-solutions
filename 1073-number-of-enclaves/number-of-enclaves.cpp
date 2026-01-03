class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;

        grid[r][c] = 0; // mark as visited / water

        for (auto& d : dirs) {
            dfs(grid, r + d[0], c + d[1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 1️⃣ Flood-fill from boundary
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        // 2️⃣ Count remaining land
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
