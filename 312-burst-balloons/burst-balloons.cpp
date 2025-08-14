class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Pad with 1s at both ends to handle borders uniformly
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; ++i) a[i + 1] = nums[i];
        int m = n + 2;

        // dp[i][j] = max coins from bursting balloons exclusively in (i, j)
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Iterate over interval lengths (at least 2 apart to have space for a k)
        for (int len = 2; len < m; ++len) {
            for (int i = 0; i + len < m; ++i) {
                int j = i + len;
                // choose the last balloon k to burst in (i, j)
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
