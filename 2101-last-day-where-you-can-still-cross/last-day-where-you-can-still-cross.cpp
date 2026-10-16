
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = cells.size();
        int ans = 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));

            for (int i = 0; i < day; i++) {
                int r = cells[i][0] - 1;
                int c = cells[i][1] - 1;
                grid[r][c] = 1;
            }

            queue<pair<int, int>> q;

            for (int j = 0; j < col; j++) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    grid[0][j] = 1;
                }
            }

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == row - 1) {
                    return true;
                }

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < row &&
                        nc >= 0 && nc < col &&
                        grid[nr][nc] == 0) {

                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }

            return false;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCross(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
