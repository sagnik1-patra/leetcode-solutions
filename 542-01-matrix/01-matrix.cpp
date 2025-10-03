class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Step 1: push all 0s into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // Step 2: BFS from all 0s
        vector<int> dirs = {0,1,0,-1,0};
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k], nc = c + dirs[k+1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return dist;
    }
};