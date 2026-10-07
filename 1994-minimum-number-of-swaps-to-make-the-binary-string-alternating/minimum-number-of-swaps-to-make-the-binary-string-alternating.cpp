class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();

        int zeros = 0;
        int ones = 0;

        for (char c : s) {
            if (c == '0')
                zeros++;
            else
                ones++;
        }

        // Impossible to create an alternating string
        if (abs(zeros - ones) > 1) {
            return -1;
        }

        // Count mismatches for pattern starting with '0'
        int mismatch0 = 0;

        // Count mismatches for pattern starting with '1'
        int mismatch1 = 0;

        for (int i = 0; i < n; i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0)
                mismatch0++;

            if (s[i] != expected1)
                mismatch1++;
        }

        // More zeros → pattern must start with 0
        if (zeros > ones) {
            return mismatch0 / 2;
        }

        // More ones → pattern must start with 1
        if (ones > zeros) {
            return mismatch1 / 2;
        }

        // Equal counts → either pattern is possible
        return min(mismatch0, mismatch1) / 2;
    }
};