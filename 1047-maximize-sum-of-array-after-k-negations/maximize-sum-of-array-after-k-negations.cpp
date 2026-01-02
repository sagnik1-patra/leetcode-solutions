class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // Sort by absolute value descending
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        // Flip negative numbers first
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        // If k is odd, flip the smallest absolute value
        if (k % 2 == 1) {
            nums.back() = -nums.back();
        }

        // Compute final sum
        int sum = 0;
        for (int x : nums) sum += x;

        return sum;
    }
};
