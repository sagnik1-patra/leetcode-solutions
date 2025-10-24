class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0); // prefix sum
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + nums[i];
        
        vector<int> left(n, 0), right(n, 0);
        vector<int> res(3, 0);

        // left[i] = starting index of best subarray on the left of i (inclusive)
        int best = 0;
        for (int i = 0; i <= n - k; ++i) {
            if (sum[i + k] - sum[i] > sum[best + k] - sum[best])
                best = i;
            left[i] = best;
        }

        // right[i] = starting index of best subarray on the right of i (inclusive)
        best = n - k;
        for (int i = n - k; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= sum[best + k] - sum[best])
                best = i;
            right[i] = best;
        }

        int maxSum = 0;
        // Try all middle intervals
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int l = left[mid - k];
            int r = right[mid + k];
            int total = (sum[l + k] - sum[l]) +
                        (sum[mid + k] - sum[mid]) +
                        (sum[r + k] - sum[r]);
            if (total > maxSum) {
                maxSum = total;
                res = {l, mid, r};
            }
        }
        return res;
    }
};