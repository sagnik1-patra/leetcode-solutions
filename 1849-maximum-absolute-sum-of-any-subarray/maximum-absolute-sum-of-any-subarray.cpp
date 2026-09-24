class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int maxPrefix = 0;
        int minPrefix = 0;

        for (int num : nums) {
            prefixSum += num;

            maxPrefix = max(maxPrefix, prefixSum);
            minPrefix = min(minPrefix, prefixSum);
        }

        return maxPrefix - minPrefix;
    }
};