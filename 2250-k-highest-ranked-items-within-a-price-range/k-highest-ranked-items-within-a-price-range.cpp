
class Solution {
public:
    vector<vector<int>> highestRankedKItems(
        vector<vector<int>>& grid,
        vector<int>& pricing,
        vector<int>& start,
        int k
    ) {
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<tuple<int, int, int, int>> items;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            int price = grid[r][c];

            if (price >= pricing[0] && price <= pricing[1]) {
                items.push_back({dist, price, r, c});
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc] &&
                    grid[nr][nc] != 0) {

                    visited[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        sort(items.begin(), items.end());

        vector<vector<int>> ans;

        for (int i = 0; i < min(k, (int)items.size()); i++) {
            auto [dist, price, r, c] = items[i];
            ans.push_back({r, c});
        }

        return ans;
    }
};
