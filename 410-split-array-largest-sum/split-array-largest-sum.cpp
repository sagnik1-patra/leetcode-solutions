class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;
        for (int x : nums) {
            lo = max(lo, (long long)x);
            hi += x;
        }

        auto can = [&](long long cap) {
            int parts = 1;
            long long cur = 0;
            for (int x : nums) {
                if (cur + x > cap) {
                    parts++;
                    cur = x;
                    if (parts > k) return false;
                } else {
                    cur += x;
                }
            }
            return true;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (can(mid)) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }
};
