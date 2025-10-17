class Solution {
public:
    // BFS helper to compute shortest path between two points in the forest
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({sx, sy});
        dist[sx][sy] = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if (nx == tx && ny == ty) return dist[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
        return -1; // unreachable
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();

        // Step 1: Collect all trees (value > 1)
        vector<tuple<int,int,int>> trees; // (height, row, col)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
            }
        }

        // Step 2: Sort trees by height (must cut from shortest to tallest)
        sort(trees.begin(), trees.end());

        int totalSteps = 0;
        int sx = 0, sy = 0; // start from top-left

        // Step 3: Visit trees in ascending height order
        for (auto& [h, tx, ty] : trees) {
            int d = bfs(forest, sx, sy, tx, ty);
            if (d == -1) return -1; // unreachable tree
            totalSteps += d;
            sx = tx; sy = ty; // move to next starting point
        }

        return totalSteps;
    }
};
