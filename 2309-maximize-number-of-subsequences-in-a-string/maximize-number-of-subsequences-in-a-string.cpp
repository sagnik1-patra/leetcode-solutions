
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long count1 = 0;
        long long count2 = 0;
        long long ans = 0;

        for (char c : text) {
            if (c == pattern[1]) {
                ans += count1;
                count2++;
            }

            if (c == pattern[0]) {
                count1++;
            }
        }

        return ans + max(count1, count2);
    }
};
