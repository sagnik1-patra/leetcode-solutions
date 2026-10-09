
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        int count1 = 0, count2 = 0;
        int ans = n;

        for (int i = 0; i < 2 * n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected1)
                count1++;

            if (s[i] != expected2)
                count2++;

            if (i >= n) {
                int left = i - n;

                char old1 = (left % 2 == 0) ? '0' : '1';
                char old2 = (left % 2 == 0) ? '1' : '0';

                if (s[left] != old1)
                    count1--;

                if (s[left] != old2)
                    count2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(count1, count2));
            }
        }

        return ans;
    }
};
