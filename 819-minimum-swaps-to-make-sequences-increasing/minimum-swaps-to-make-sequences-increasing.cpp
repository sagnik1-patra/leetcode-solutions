class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> keep(n, INT_MAX), swap(n, INT_MAX);

        // Base case
        keep[0] = 0;   // No swap at index 0
        swap[0] = 1;   // Swap at index 0

        for (int i = 1; i < n; i++) {
            bool noSwapPossible = (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]);
            bool crossSwapPossible = (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]);

            if (noSwapPossible) {
                // If both arrays are increasing naturally
                keep[i] = keep[i - 1];
                swap[i] = swap[i - 1] + 1;  // If we also swap this one, add 1
            }

            if (crossSwapPossible) {
                // If we can make them increasing by swapping one of them
                keep[i] = min(keep[i], swap[i - 1]);
                swap[i] = min(swap[i], keep[i - 1] + 1);
            }
        }

        return min(keep[n - 1], swap[n - 1]);
    }
};