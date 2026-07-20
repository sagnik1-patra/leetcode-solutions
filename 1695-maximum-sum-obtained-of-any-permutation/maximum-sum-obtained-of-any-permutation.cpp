class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<long long> freq(n, 0);
        
        // Step 1: difference array
        for (auto &r : requests) {
            freq[r[0]]++;
            if (r[1] + 1 < n) freq[r[1] + 1]--;
        }
        
        // Step 2: prefix sum
        for (int i = 1; i < n; i++) {
            freq[i] += freq[i - 1];
        }
        
        // Step 3: sort both
        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());
        
        // Step 4: maximize sum
        long long result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + freq[i] * nums[i]) % MOD;
        }
        
        return result;
    }
};