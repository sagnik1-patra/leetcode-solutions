class Solution {
public:
    int minOperations(string s) {
        int mismatch1 = 0;
        int mismatch2 = 0;

        for (int i = 0; i < s.size(); i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected1) {
                mismatch1++;
            }

            if (s[i] != expected2) {
                mismatch2++;
            }
        }

        return min(mismatch1, mismatch2);
    }
};