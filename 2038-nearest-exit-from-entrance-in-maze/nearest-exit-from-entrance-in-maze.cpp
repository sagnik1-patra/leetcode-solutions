
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;

        int row = entrance[0];
        int col = entrance[1];

        q.push({row, col});
        maze[row][col] = '+';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                // Check if current cell is an exit
                if (steps > 0 &&
                    (r == 0 || r == m - 1 ||
                     c == 0 || c == n - 1)) {
                    return steps;
                }

                // Explore all four directions
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        maze[nr][nc] == '.') {

                        q.push({nr, nc});
                        maze[nr][nc] = '+';
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
