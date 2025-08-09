class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> window; // use long long to avoid overflow
        for (int i = 0; i < nums.size(); i++) {
            // Find the smallest number >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            // Check if this number also <= nums[i] + valueDiff
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);

            // Maintain the sliding window size
            if (window.size() > indexDiff) {
                window.erase(window.find(nums[i - indexDiff]));
            }
        }
        return false;
    }
};