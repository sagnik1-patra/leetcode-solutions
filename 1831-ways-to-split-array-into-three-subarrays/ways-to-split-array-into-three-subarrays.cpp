class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long total = prefix[n - 1];
        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            long long leftSum = prefix[i];

            // First valid ending position of mid
            int l = lower_bound(
                prefix.begin() + i + 1,
                prefix.begin() + n - 1,
                2 * leftSum
            ) - prefix.begin();

            // Last valid ending position of mid
            int r = upper_bound(
                prefix.begin() + i + 1,
                prefix.begin() + n - 1,
                (total + leftSum) / 2
            ) - prefix.begin() - 1;

            if (l <= r) {
                ans = (ans + (r - l + 1)) % MOD;
            }
        }

        return ans;
    }
};