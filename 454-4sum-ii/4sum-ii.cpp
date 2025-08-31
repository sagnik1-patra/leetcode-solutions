class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                     vector<int>& nums3, vector<int>& nums4) {
        unordered_map<long long, int> cnt;
        cnt.reserve((size_t)nums1.size() * nums2.size() * 2);

        for (int a : nums1)
            for (int b : nums2)
                ++cnt[(long long)a + b];

        long long ans = 0;
        for (int c : nums3)
            for (int d : nums4) {
                long long s = (long long)c + d;
                auto it = cnt.find(-s);
                if (it != cnt.end()) ans += it->second;
            }
        return (int)ans;
    }
};
