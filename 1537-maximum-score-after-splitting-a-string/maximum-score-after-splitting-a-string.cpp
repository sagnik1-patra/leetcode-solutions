class Solution {
public:
    int maxScore(string s) {
        int onesRight = 0;

        for (char ch : s) {
            if (ch == '1') onesRight++;
        }

        int zerosLeft = 0;
        int ans = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                zerosLeft++;
            } else {
                onesRight--;
            }

            ans = max(ans, zerosLeft + onesRight);
        }

        return ans;
    }
};