class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;              // "122" → first n has exactly one '1'

        vector<int> s; s.reserve(n + 5);
        s.push_back(1);
        s.push_back(2);
        s.push_back(2);

        int ones = 1;                      // count of '1's in the current s (length ≥ 3)
        int i = 2;                         // read pointer into s for run-lengths
        int next = 1;                      // next digit to append

        while ((int)s.size() < n) {
            int cnt = s[i];                // append 'next' exactly cnt times
            for (int k = 0; k < cnt && (int)s.size() < n; ++k) {
                s.push_back(next);
                if (next == 1) ++ones;
            }
            next = 3 - next;               // toggle 1 <-> 2
            ++i;
        }
        return ones;
    }
};