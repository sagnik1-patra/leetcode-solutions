class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2); // build set from smaller
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> seen;
        vector<int> res;
        res.reserve(s.size());
        for (int x : nums2) {
            if (s.count(x) && !seen.count(x)) {
                seen.insert(x);
                res.push_back(x);
            }
        }
        return res;
    }
};
