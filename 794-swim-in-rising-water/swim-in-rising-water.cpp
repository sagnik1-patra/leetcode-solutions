class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Min-heap: {time (max elevation so far), row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<int> dirs = {1, 0, -1, 0, 1};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int t = cur[0], r = cur[1], c = cur[2];

            if (r == n - 1 && c == n - 1)
                return t;

            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dirs[k];
                int nc = c + dirs[k + 1];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc])
                    continue;
                pq.push({max(t, grid[nr][nc]), nr, nc});
            }
        }

        return -1; // should never reach here
    }
};
