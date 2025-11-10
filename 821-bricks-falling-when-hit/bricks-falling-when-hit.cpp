class Solution {
public:
    vector<int> parent, size;
    int m, n;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    int top() {
        return m * n; // virtual top node
    }

    int index(int i, int j) {
        return i * n + j;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size();
        n = grid[0].size();

        parent.resize(m * n + 1);
        size.resize(m * n + 1, 1);
        iota(parent.begin(), parent.end(), 0);

        // Copy grid to apply hits
        vector<vector<int>> copyGrid = grid;
        for (auto &h : hits) {
            int x = h[0], y = h[1];
            if (copyGrid[x][y] == 1)
                copyGrid[x][y] = 0;
        }

        // Connect stable bricks in the modified grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (copyGrid[i][j] == 1) {
                    if (i == 0) unite(index(i, j), top());
                    if (i > 0 && copyGrid[i - 1][j] == 1)
                        unite(index(i, j), index(i - 1, j));
                    if (j > 0 && copyGrid[i][j - 1] == 1)
                        unite(index(i, j), index(i, j - 1));
                }
            }
        }

        // Process hits in reverse
        vector<int> res(hits.size(), 0);
        for (int k = hits.size() - 1; k >= 0; k--) {
            int x = hits[k][0], y = hits[k][1];
            if (grid[x][y] == 0) continue; // no brick originally

            int before = size[find(top())]; // stable count before re-adding

            copyGrid[x][y] = 1;

            // Reconnect current brick
            if (x == 0) unite(index(x, y), top());
            vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && copyGrid[nx][ny] == 1) {
                    unite(index(x, y), index(nx, ny));
                }
            }

            int after = size[find(top())]; // stable count after re-adding
            res[k] = max(0, after - before - 1); // exclude the added brick itself
        }

        return res;
    }
};