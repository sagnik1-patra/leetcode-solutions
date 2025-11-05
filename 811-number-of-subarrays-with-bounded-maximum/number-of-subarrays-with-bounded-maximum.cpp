class Solution {
public:
    // Helper function: counts subarrays where max <= bound
    int countSubarrays(vector<int>& nums, int bound) {
        int count = 0, curr = 0;
        for (int x : nums) {
            if (x <= bound)
                curr++;       // extend current valid window
            else
                curr = 0;     // reset when > bound
            count += curr;    // add number of valid subarrays ending here
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // # of subarrays with max ≤ right  −  # of subarrays with max < left
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
};