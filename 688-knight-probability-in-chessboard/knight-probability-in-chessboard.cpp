class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // Directions for knight moves
        vector<pair<int,int>> dirs = {
            {2,1}, {1,2}, {-1,2}, {-2,1},
            {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
        };

        // dp[r][c] = probability of being at (r,c)
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0; // start position probability

        for (int step = 0; step < k; ++step) {
            vector<vector<double>> next(n, vector<double>(n, 0.0));
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] > 0) {
                        for (auto &d : dirs) {
                            int nr = r + d.first;
                            int nc = c + d.second;
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                next[nr][nc] += dp[r][c] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = move(next);
        }

        double ans = 0.0;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                ans += dp[r][c];

        return ans;
    }
};