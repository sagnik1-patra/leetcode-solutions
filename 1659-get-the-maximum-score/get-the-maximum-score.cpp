class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j++];
            } else {
                // common element
                long long best = max(sum1, sum2) + nums1[i];
                sum1 = sum2 = best;
                i++; j++;
            }
        }
        
        // add remaining elements
        while (i < nums1.size()) sum1 += nums1[i++];
        while (j < nums2.size()) sum2 += nums2[j++];
        
        return max(sum1, sum2) % MOD;
    }
};