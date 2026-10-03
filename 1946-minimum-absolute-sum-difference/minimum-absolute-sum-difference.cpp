class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();

        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());

        long long total = 0;
        int maxSaving = 0;

        for (int i = 0; i < n; i++) {
            int currentDiff = abs(nums1[i] - nums2[i]);

            total += currentDiff;

            // Find the nums1 value closest to nums2[i]
            auto it = lower_bound(sorted.begin(), sorted.end(), nums2[i]);

            // Candidate >= nums2[i]
            if (it != sorted.end()) {
                int newDiff = abs(*it - nums2[i]);
                maxSaving = max(maxSaving, currentDiff - newDiff);
            }

            // Candidate < nums2[i]
            if (it != sorted.begin()) {
                --it;

                int newDiff = abs(*it - nums2[i]);
                maxSaving = max(maxSaving, currentDiff - newDiff);
            }
        }

        return (total - maxSaving) % MOD;
    }
};