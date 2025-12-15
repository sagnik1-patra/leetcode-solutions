class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> result(n);

        // Sort nums1
        sort(nums1.begin(), nums1.end());

        // Store nums2 with original indices
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            b.push_back({nums2[i], i});
        }

        // Sort nums2 by value
        sort(b.begin(), b.end());

        int left = 0, right = n - 1;

        // Traverse nums2 from largest to smallest
        for (int i = n - 1; i >= 0; i--) {
            int val = b[i].first;
            int idx = b[i].second;

            if (nums1[right] > val) {
                result[idx] = nums1[right];
                right--;
            } else {
                result[idx] = nums1[left];
                left++;
            }
        }

        return result;
    }
};
