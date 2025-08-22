class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        // DFS from all Pacific-border cells (top row, left col)
        for (int j = 0; j < n; ++j) dfs(0, j, heights, pac);
        for (int i = 0; i < m; ++i) dfs(i, 0, heights, pac);

        // DFS from all Atlantic-border cells (bottom row, right col)
        for (int j = 0; j < n; ++j) dfs(m - 1, j, heights, atl);
        for (int i = 0; i < m; ++i) dfs(i, n - 1, heights, atl);

        // Cells reachable from both oceans
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }

private:
    void dfs(int i, int j, const vector<vector<int>>& h, vector<vector<int>>& vis) {
        if (vis[i][j]) return;
        vis[i][j] = 1;
        static const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int m = h.size(), n = h[0].size();
        for (auto &d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            // Reverse flow: we can go from (i,j) to neighbor (ni,nj)
            // if neighbor is >= current (so water can flow down from neighbor to (i,j))
            if (!vis[ni][nj] && h[ni][nj] >= h[i][j]) {
                dfs(ni, nj, h, vis);
            }
        }
    }
};
