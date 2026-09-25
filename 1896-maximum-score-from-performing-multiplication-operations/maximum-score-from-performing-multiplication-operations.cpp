class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int left = i; left >= 0; left--) {
                int right = n - 1 - (i - left);

                int takeLeft =
                    multipliers[i] * nums[left] +
                    dp[i + 1][left + 1];

                int takeRight =
                    multipliers[i] * nums[right] +
                    dp[i + 1][left];

                dp[i][left] = max(takeLeft, takeRight);
            }
        }

        return dp[0][0];
    }
};