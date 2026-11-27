class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;

    vector<vector<int>> dp;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(int r, int c, vector<vector<int>>& grid) {

        if (dp[r][c] != -1)
            return dp[r][c];

        // Single-cell path
        long long count = 1;

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] > grid[r][c]) {

                count = (count + dfs(nr, nc, grid)) % MOD;
            }
        }

        return dp[r][c] = count;
    }

    int countPaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                ans = (ans + dfs(i, j, grid)) % MOD;
            }
        }

        return ans;
    }
};