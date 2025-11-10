class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());

        // Early pruning: if no subset can make equal average, return false
        bool possible = false;
        for (int k = 1; k < n; ++k) {
            if ((totalSum * k) % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        // DP approach using unordered_set for subset sums
        vector<unordered_set<int>> dp(n / 2 + 1);
        dp[0].insert(0);

        for (int num : nums) {
            for (int k = n / 2; k >= 1; --k) {
                for (int prevSum : dp[k - 1]) {
                    dp[k].insert(prevSum + num);
                }
            }
        }

        for (int k = 1; k <= n / 2; ++k) {
            if ((totalSum * k) % n != 0) continue;
            int targetSum = (totalSum * k) / n;
            if (dp[k].count(targetSum)) return true;
        }

        return false;
    }
};