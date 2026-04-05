class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dpSum(n, vector<int>(n, -1));
        vector<vector<int>> dpWays(n, vector<int>(n, 0));

        // Start from 'S'
        dpSum[n-1][n-1] = 0;
        dpWays[n-1][n-1] = 1;

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;

                // Skip starting cell
                if (i == n-1 && j == n-1) continue;

                int maxSum = -1;
                int ways = 0;

                // Check 3 directions
                vector<pair<int,int>> dirs = {{i+1,j},{i,j+1},{i+1,j+1}};

                for (auto [x, y] : dirs) {
                    if (x < n && y < n && dpSum[x][y] != -1) {
                        if (dpSum[x][y] > maxSum) {
                            maxSum = dpSum[x][y];
                            ways = dpWays[x][y];
                        } else if (dpSum[x][y] == maxSum) {
                            ways = (ways + dpWays[x][y]) % MOD;
                        }
                    }
                }

                if (maxSum == -1) continue;

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

                dpSum[i][j] = maxSum + val;
                dpWays[i][j] = ways % MOD;
            }
        }

        if (dpSum[0][0] == -1) return {0, 0};

        return {dpSum[0][0], dpWays[0][0]};
    }
};