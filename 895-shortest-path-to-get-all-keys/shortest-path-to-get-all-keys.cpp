class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startX, startY;
        int allKeysMask = 0;

        // Locate start and count keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    allKeysMask |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        queue<tuple<int,int,int>> q;
        bool visited[30][30][64] = {false};

        q.push({startX, startY, 0});
        visited[startX][startY][0] = true;

        int steps = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y, mask] = q.front();
                q.pop();

                if (mask == allKeysMask)
                    return steps;

                for (auto& d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    int newMask = mask;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    char cell = grid[nx][ny];
                    if (cell == '#') continue;

                    // Lock
                    if (cell >= 'A' && cell <= 'F') {
                        if (!(mask & (1 << (cell - 'A'))))
                            continue;
                    }

                    // Key
                    if (cell >= 'a' && cell <= 'f') {
                        newMask |= (1 << (cell - 'a'));
                    }

                    if (!visited[nx][ny][newMask]) {
                        visited[nx][ny][newMask] = true;
                        q.push({nx, ny, newMask});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
