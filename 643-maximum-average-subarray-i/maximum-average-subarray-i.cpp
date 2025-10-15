class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double curr_sum = 0;

        // Compute sum of first k elements
        for (int i = 0; i < k; ++i) {
            curr_sum += nums[i];
        }

        double max_sum = curr_sum;

        // Sliding window
        for (int i = k; i < n; ++i) {
            curr_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum / k;
    }
};
