class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Initialize queue with all rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;
        vector<int> dir = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dir[d];
                    int ny = y + dir[d + 1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
