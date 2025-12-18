class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long maxCount = pow2[i];
            long long minCount = pow2[n - 1 - i];
            ans = (ans + nums[i] * (maxCount - minCount)) % MOD;
        }

        // Ensure non-negative
        if (ans < 0) ans += MOD;
        return ans;
    }
};
