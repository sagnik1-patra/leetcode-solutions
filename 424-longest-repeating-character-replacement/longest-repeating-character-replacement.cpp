class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};
        int l = 0, best = 0, maxFreq = 0;

        for (int r = 0; r < (int)s.size(); ++r) {
            int c = s[r] - 'A';
            maxFreq = max(maxFreq, ++cnt[c]);

            // shrink if more than k replacements needed
            while ((r - l + 1) - maxFreq > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
