class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // In case k > n

        // Reverse helper
        auto reverse = [&](int start, int end) {
            while (start < end) {
                swap(nums[start++], nums[end--]);
            }
        };

        reverse(0, n - 1);      // Step 1: Reverse entire array
        reverse(0, k - 1);      // Step 2: Reverse first k elements
        reverse(k, n - 1);      // Step 3: Reverse remaining n-k elements
    }
};
