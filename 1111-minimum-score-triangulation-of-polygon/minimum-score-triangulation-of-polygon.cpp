class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length is the distance between i and j
        for (int length = 2; length < n; length++) {
            for (int i = 0; i + length < n; i++) {
                int j = i + length;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + dp[k][j] +
                        values[i] * values[k] * values[j]
                    );
                }
            }
        }

        return dp[0][n - 1];
    }
};
