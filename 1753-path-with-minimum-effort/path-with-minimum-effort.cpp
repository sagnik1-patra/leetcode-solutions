class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // effort[r][c] = minimum possible maximum effort
        // required to reach cell (r, c)
        vector<vector<int>> effort(
            rows, vector<int>(cols, INT_MAX)
        );

        // {effort, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [currentEffort, r, c] = pq.top();
            pq.pop();

            // Destination reached
            if (r == rows - 1 && c == cols - 1)
                return currentEffort;

            // Ignore an outdated entry
            if (currentEffort > effort[r][c])
                continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols) {

                    int difference =
                        abs(heights[r][c] - heights[nr][nc]);

                    // Important part:
                    // effort of the entire path is the
                    // maximum difference encountered
                    int newEffort =
                        max(currentEffort, difference);

                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};