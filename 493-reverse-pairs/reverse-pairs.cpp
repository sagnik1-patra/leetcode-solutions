class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        return (int)mergeCount(nums, 0, (int)nums.size() - 1);
    }

private:
    long long mergeCount(vector<int>& a, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        long long cnt = 0;
        cnt += mergeCount(a, lo, mid);
        cnt += mergeCount(a, mid + 1, hi);

        // Count cross reverse pairs where i in [lo..mid], j in [mid+1..hi]
        int j = mid + 1;
        for (int i = lo; i <= mid; ++i) {
            while (j <= hi && (long long)a[i] > 2LL * (long long)a[j]) ++j;
            cnt += (j - (mid + 1));
        }

        // Standard merge step
        vector<int> tmp;
        tmp.reserve(hi - lo + 1);
        int i = lo; j = mid + 1;
        while (i <= mid && j <= hi) {
            if (a[i] <= a[j]) tmp.push_back(a[i++]);
            else tmp.push_back(a[j++]);
        }
        while (i <= mid) tmp.push_back(a[i++]);
        while (j <= hi) tmp.push_back(a[j++]);

        // Copy back
        for (int k = 0; k < (int)tmp.size(); ++k) a[lo + k] = tmp[k];
        return cnt;
    }
};
