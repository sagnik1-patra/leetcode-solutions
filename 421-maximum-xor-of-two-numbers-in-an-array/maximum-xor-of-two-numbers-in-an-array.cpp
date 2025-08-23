class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0;
        for (int b = 31; b >= 0; --b) {
            mask |= (1 << b);
            unordered_set<int> pref;
            pref.reserve(nums.size() * 2);
            for (int x : nums) pref.insert(x & mask);

            int candidate = ans | (1 << b);
            bool ok = false;
            for (int p : pref) {
                // If p ^ candidate exists among prefixes, then candidate is achievable
                if (pref.count(p ^ candidate)) { ok = true; break; }
            }
            if (ok) ans = candidate;
        }
        return ans;
    }
};
