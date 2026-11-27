class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, 
                            vector<int>& nums2) {

        int sum1 = 0, sum2 = 0;
        int curr1 = 0, curr2 = 0;
        int gain1 = 0, gain2 = 0;

        for (int i = 0; i < nums1.size(); i++) {

            sum1 += nums1[i];
            sum2 += nums2[i];

            // Maximum gain for nums1
            curr1 = max(0, curr1 + nums2[i] - nums1[i]);
            gain1 = max(gain1, curr1);

            // Maximum gain for nums2
            curr2 = max(0, curr2 + nums1[i] - nums2[i]);
            gain2 = max(gain2, curr2);
        }

        return max(sum1 + gain1, sum2 + gain2);
    }
};