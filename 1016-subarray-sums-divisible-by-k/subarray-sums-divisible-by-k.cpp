class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // prefix sum divisible by k initially

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;
            int rem = prefixSum % k;

            // Handle negative modulo
            if (rem < 0) rem += k;

            if (freq.count(rem)) {
                count += freq[rem];
            }

            freq[rem]++;
        }

        return count;
    }
};
