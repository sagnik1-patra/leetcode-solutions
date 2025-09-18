class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (target > total || target < -total) return 0;
        if ((target + total) % 2 != 0) return 0;

        int sumP = (target + total) / 2;
        if (sumP < 0) return 0;

        vector<long long> dp(sumP + 1, 0);
        dp[0] = 1;  // one way to make sum 0

        for (int num : nums) {
            for (int s = sumP; s >= num; --s) {
                dp[s] += dp[s - num];
            }
        }
        return (int)dp[sumP];
    }
};
