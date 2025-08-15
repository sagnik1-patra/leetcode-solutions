class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0)); // memo[r][c] = best length starting here
        int ans = 0;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                ans = max(ans, dfs(matrix, r, c, memo));
        return ans;
    }

private:
    // 4 directions
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int dfs(const vector<vector<int>>& a, int r, int c, vector<vector<int>>& memo) {
        if (memo[r][c]) return memo[r][c];
        int m = a.size(), n = a[0].size();
        int best = 1; // at least the cell itself
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && a[nr][nc] > a[r][c]) {
                best = max(best, 1 + dfs(a, nr, nc, memo));
            }
        }
        return memo[r][c] = best;
    }
};
