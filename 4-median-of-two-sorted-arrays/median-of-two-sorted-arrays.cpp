class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1); 

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m, halfLen = (m + n + 1) / 2;
        
        while (left <= right) {
            int i = (left + right) / 2; 
            int j = halfLen - i;        
            
            int leftMax1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightMin1 = (i == m) ? INT_MAX : nums1[i];
            int leftMax2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightMin2 = (j == n) ? INT_MAX : nums2[j];

            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                
                if ((m + n) % 2 == 0)
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
                else
                    return max(leftMax1, leftMax2);
            } else if (leftMax1 > rightMin2) {
                right = i - 1; 
            } else {
                left = i + 1; 
            }
        }
        
        return 0.0;     
    }
};