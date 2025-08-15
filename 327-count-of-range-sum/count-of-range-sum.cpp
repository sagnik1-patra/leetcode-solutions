class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + (long long)nums[i];
        return (int)mergeCount(prefix, 0, n + 1, (long long)lower, (long long)upper);
    }

private:
    long long mergeCount(vector<long long>& s, int l, int r, long long lo, long long hi) {
        if (r - l <= 1) return 0;
        int m = (l + r) >> 1;
        long long cnt = mergeCount(s, l, m, lo, hi) + mergeCount(s, m, r, lo, hi);

        // Count valid pairs with left in [l, m) and right in [m, r)
        int j = m, k = m;
        for (int i = l; i < m; ++i) {
            // Find first j such that s[j] - s[i] >= lo
            while (j < r && s[j] - s[i] < lo) ++j;
            // Find first k such that s[k] - s[i] > hi
            while (k < r && s[k] - s[i] <= hi) ++k;
            cnt += (k - j);
        }

        // Merge the two sorted halves s[l..m) and s[m..r)
        vector<long long> tmp;
        tmp.reserve(r - l);
        int p = l, q = m;
        while (p < m && q < r) {
            if (s[p] <= s[q]) tmp.push_back(s[p++]);
            else              tmp.push_back(s[q++]);
        }
        while (p < m) tmp.push_back(s[p++]);
        while (q < r) tmp.push_back(s[q++]);
        for (int i = 0; i < (int)tmp.size(); ++i) s[l + i] = tmp[i];

        return cnt;
    }
};
