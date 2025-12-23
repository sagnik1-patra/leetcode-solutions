class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int maxKadane = nums[0], currMax = 0;
        int minKadane = nums[0], currMin = 0;

        for (int x : nums) {
            total += x;

            currMax = max(x, currMax + x);
            maxKadane = max(maxKadane, currMax);

            currMin = min(x, currMin + x);
            minKadane = min(minKadane, currMin);
        }

        // All numbers are negative
        if (maxKadane < 0) return maxKadane;

        return max(maxKadane, total - minKadane);
    }
};
