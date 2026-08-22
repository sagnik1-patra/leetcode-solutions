class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freqMap;

        for (int x : nums) {
            freqMap[x]++;
        }

        vector<int> freq;
        for (auto& p : freqMap) {
            freq.push_back(p.second);
        }

        int m = quantity.size();
        int totalMasks = 1 << m;

        vector<int> subsetSum(totalMasks, 0);

        for (int mask = 1; mask < totalMasks; mask++) {
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    subsetSum[mask] += quantity[i];
                }
            }
        }

        vector<bool> dp(totalMasks, false);
        dp[0] = true;

        for (int count : freq) {
            vector<bool> next = dp;

            for (int mask = 0; mask < totalMasks; mask++) {
                if (!dp[mask]) continue;

                int remaining = (totalMasks - 1) ^ mask;

                for (int sub = remaining; sub > 0; sub = (sub - 1) & remaining) {
                    if (subsetSum[sub] <= count) {
                        next[mask | sub] = true;
                    }
                }
            }

            dp = next;
        }

        return dp[totalMasks - 1];
    }
};