class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int maxDist = 0;

        while (i < nums1.size() && j < nums2.size()) {

            // Valid pair
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            }
            else {
                i++;

                // Ensure i <= j
                if (i > j) {
                    j = i;
                }
            }
        }

        return maxDist;
    }
};