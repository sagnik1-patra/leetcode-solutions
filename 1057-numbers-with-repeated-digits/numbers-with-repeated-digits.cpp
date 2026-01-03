class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int len = s.size();
        int unique = 0;

        // Helper to compute permutations P(m, k)
        auto perm = [&](int m, int k) {
            int res = 1;
            for (int i = 0; i < k; i++) {
                res *= (m - i);
            }
            return res;
        };

        // 1️⃣ Count numbers with fewer digits
        for (int i = 1; i < len; i++) {
            unique += 9 * perm(9, i - 1);
        }

        // 2️⃣ Count numbers with same digits
        vector<bool> used(10, false);
        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            for (int d = (i == 0 ? 1 : 0); d < digit; d++) {
                if (!used[d]) {
                    unique += perm(10 - (i + 1), len - i - 1);
                }
            }
            if (used[digit]) break;
            used[digit] = true;
            if (i == len - 1) unique++;
        }

        return n - unique;
    }
};
