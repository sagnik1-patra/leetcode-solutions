class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;
        if (n1 == 0 || n2 == 0 || k == 0) return ans;

        using T = tuple<long long,int,int>; // (sum, i, j)
        auto cmp = [](const T& a, const T& b){ return get<0>(a) > get<0>(b); };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        // seed with pairs (i, 0)
        int limit = min(k, n1);
        for (int i = 0; i < limit; ++i)
            pq.emplace((long long)nums1[i] + nums2[0], i, 0);

        while (!pq.empty() && (int)ans.size() < k) {
            auto [sum, i, j] = pq.top(); pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < n2) {
                pq.emplace((long long)nums1[i] + nums2[j+1], i, j+1);
            }
        }
        return ans;
    }
};
