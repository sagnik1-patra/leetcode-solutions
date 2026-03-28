class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // Optimization: if k is large enough → direct shortest path
        if (k >= m + n - 2) return m + n - 2;

        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<tuple<int,int,int,int>> q; // row, col, steps, k_remaining

        q.push({0, 0, 0, k});
        visited[0][0] = k;

        vector<int> dirs = {0,1,0,-1,0};

        while (!q.empty()) {
            auto [r, c, steps, rem_k] = q.front();
            q.pop();

            if (r == m-1 && c == n-1) return steps;

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d+1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int new_k = rem_k - grid[nr][nc];

                if (new_k < 0) continue;

                // Only visit if better k remaining
                if (visited[nr][nc] >= new_k) continue;

                visited[nr][nc] = new_k;
                q.push({nr, nc, steps + 1, new_k});
            }
        }

        return -1;
    }
};