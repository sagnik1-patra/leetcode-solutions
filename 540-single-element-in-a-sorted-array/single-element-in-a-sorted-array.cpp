class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // ensure mid is even (pair start)
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                // single element is after this pair
                left = mid + 2;
            } else {
                // single element is before or at mid
                right = mid;
            }
        }
        return nums[left];
    }
};