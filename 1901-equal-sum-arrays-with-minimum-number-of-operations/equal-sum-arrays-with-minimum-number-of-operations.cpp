class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Check if equal sums are even possible
        if (n1 * 6 < n2 || n2 * 6 < n1) {
            return -1;
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (sum1 == sum2) {
            return 0;
        }

        // Make nums1 the array with smaller sum
        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }

        int difference = sum2 - sum1;

        vector<int> gains;

        // Increase values in smaller-sum array
        for (int x : nums1) {
            gains.push_back(6 - x);
        }

        // Decrease values in larger-sum array
        for (int x : nums2) {
            gains.push_back(x - 1);
        }

        sort(gains.rbegin(), gains.rend());

        int operations = 0;

        for (int gain : gains) {
            difference -= gain;
            operations++;

            if (difference <= 0) {
                return operations;
            }
        }

        return -1;
    }
};