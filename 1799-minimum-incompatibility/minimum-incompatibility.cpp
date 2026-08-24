class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int groupSize = n / k;
        int totalMasks = 1 << n;
        const int INF = 1e9;

        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > k) return -1;
        }

        vector<int> cost(totalMasks, -1);

        for (int mask = 0; mask < totalMasks; mask++) {
            if (__builtin_popcount(mask) != groupSize) continue;

            unordered_set<int> seen;
            int mn = INT_MAX;
            int mx = INT_MIN;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (seen.count(nums[i])) {
                        valid = false;
                        break;
                    }

                    seen.insert(nums[i]);
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }

            if (valid) {
                cost[mask] = mx - mn;
            }
        }

        vector<int> dp(totalMasks, INF);
        dp[0] = 0;

        for (int mask = 0; mask < totalMasks; mask++) {
            if (dp[mask] == INF) continue;

            int first = 0;
            while (first < n && (mask & (1 << first))) {
                first++;
            }

            if (first == n) continue;

            int remaining = ((1 << n) - 1) ^ mask;

            for (int sub = remaining; sub; sub = (sub - 1) & remaining) {
                if (!(sub & (1 << first))) continue;
                if (cost[sub] == -1) continue;

                dp[mask | sub] =
                    min(dp[mask | sub], dp[mask] + cost[sub]);
            }
        }

        return dp[totalMasks - 1] == INF ? -1 : dp[totalMasks - 1];
    }
};