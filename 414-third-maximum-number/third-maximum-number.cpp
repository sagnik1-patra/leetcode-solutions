class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
        bool fset = false, sset = false, tset = false;

        for (int x : nums) {
            long long v = x;
            // skip duplicates of current maxima
            if (fset && v == first) continue;
            if (sset && v == second) continue;
            if (tset && v == third) continue;

            if (!fset || v > first) {
                // shift down
                third = second; tset = sset;
                second = first; sset = fset;
                first = v;      fset = true;
            } else if (!sset || v > second) {
                third = second; tset = sset;
                second = v;     sset = true;
            } else if (!tset || v > third) {
                third = v;      tset = true;
            }
        }
        return tset ? (int)third : (int)first;
    }
};
