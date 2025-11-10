class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1, 0.0);

        // Step 1: Prefix sum for fast range sum lookup
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // dp[i][j] = max sum of averages for first i elements with j partitions
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));

        // Base case: 1 partition (whole subarray)
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }

        // Step 2: Compute DP
        for (int j = 2; j <= k; j++) {          // number of partitions
            for (int i = j; i <= n; i++) {      // number of elements considered
                for (int x = j - 1; x < i; x++) {
                    double avg = (prefix[i] - prefix[x]) / (i - x);
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + avg);
                }
            }
        }

        return dp[n][k];
    }
};