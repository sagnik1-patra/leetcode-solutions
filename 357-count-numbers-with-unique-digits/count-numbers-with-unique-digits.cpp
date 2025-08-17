class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;          // only 0
        n = min(n, 10);                 // there are only 10 digits
        int ans = 10;                   // for n = 1
        int unique = 9;                 // choices for first digit (1..9)
        int avail = 9;                  // remaining digits available

        for (int len = 2; len <= n; ++len) {
            unique *= avail;            // multiply by remaining choices
            ans += unique;
            --avail;
        }
        return ans;
    }
};
