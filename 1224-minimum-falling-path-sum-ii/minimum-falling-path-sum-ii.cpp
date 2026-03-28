class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> dp = grid[0];

        for (int i = 1; i < n; i++) {
            // Find min1 and min2 from previous row
            int min1 = INT_MAX, min2 = INT_MAX;
            int col1 = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                    col1 = j;
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                }
            }

            vector<int> new_dp(n);

            for (int j = 0; j < n; j++) {
                if (j == col1) {
                    new_dp[j] = grid[i][j] + min2;
                } else {
                    new_dp[j] = grid[i][j] + min1;
                }
            }

            dp = new_dp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};