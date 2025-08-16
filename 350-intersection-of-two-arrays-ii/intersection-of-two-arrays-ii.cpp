class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2); // build freq from smaller
        unordered_map<int,int> cnt;
        cnt.reserve(nums1.size() * 2);
        for (int x : nums1) ++cnt[x];

        vector<int> res;
        res.reserve(min(nums1.size(), nums2.size()));
        for (int x : nums2) {
            auto it = cnt.find(x);
            if (it != cnt.end() && it->second > 0) {
                res.push_back(x);
                if (--it->second == 0) cnt.erase(it);
            }
        }
        return res;
    }
};
