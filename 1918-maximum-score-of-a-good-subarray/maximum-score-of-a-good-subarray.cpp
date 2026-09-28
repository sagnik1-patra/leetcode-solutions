class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int left = k;
        int right = k;

        int minVal = nums[k];
        int ans = nums[k];

        while (left > 0 || right < n - 1) {

            // Expand toward the larger neighboring value
            if (left == 0) {
                right++;
                minVal = min(minVal, nums[right]);
            }
            else if (right == n - 1) {
                left--;
                minVal = min(minVal, nums[left]);
            }
            else if (nums[left - 1] < nums[right + 1]) {
                right++;
                minVal = min(minVal, nums[right]);
            }
            else {
                left--;
                minVal = min(minVal, nums[left]);
            }

            int length = right - left + 1;

            ans = max(ans, minVal * length);
        }

        return ans;
    }
};