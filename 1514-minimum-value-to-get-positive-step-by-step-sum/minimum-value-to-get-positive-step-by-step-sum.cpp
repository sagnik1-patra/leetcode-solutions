class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefixSum = 0;
        int minPrefixSum = 0;

        for (int num : nums) {
            prefixSum += num;
            minPrefixSum = min(minPrefixSum, prefixSum);
        }

        return 1 - minPrefixSum;
    }
};