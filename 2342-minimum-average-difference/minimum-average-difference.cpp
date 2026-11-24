class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        long long totalSum = 0;
        long long prefixSum = 0;
        long long minDiff = LLONG_MAX;

        int ans = 0;

        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            long long leftAvg = prefixSum / (i + 1);
            long long rightAvg = 0;

            if (i != n - 1) {
                rightAvg = (totalSum - prefixSum) / (n - i - 1);
            }

            long long diff = abs(leftAvg - rightAvg);

            if (diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }

        return ans;
    }
};