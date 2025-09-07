class Solution {
public:
    int findSubstringInWraproundString(string s) {
        if (s.empty()) return 0;
        vector<int> best(26, 0);
        int cur = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            if (i > 0 && ( (s[i] - s[i-1] + 26) % 26 == 1 )) {
                ++cur;                // continues the wraparound chain
            } else {
                cur = 1;              // start a new chain
            }
            int idx = s[i] - 'a';
            best[idx] = max(best[idx], cur);
        }

        long long ans = 0;
        for (int x : best) ans += x;
        return (int)ans;
    }
};