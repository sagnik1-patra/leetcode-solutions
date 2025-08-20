class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[128] = {0};
        for (char c : s) cnt[(int)c]++;

        int length = 0;
        bool hasOdd = false;
        for (int i = 0; i < 128; ++i) {
            length += (cnt[i] / 2) * 2;   // use pairs
            if (cnt[i] % 2) hasOdd = true;
        }
        return length + (hasOdd ? 1 : 0); // center if any odd exists
    }
};
