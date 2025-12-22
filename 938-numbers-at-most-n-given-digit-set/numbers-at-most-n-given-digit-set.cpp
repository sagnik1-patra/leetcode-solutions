class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int L = s.size();
        int d = digits.size();
        int ans = 0;

        // Part 1: lengths smaller than n
        for (int len = 1; len < L; len++) {
            ans += pow(d, len);
        }

        // Part 2: same length as n
        for (int i = 0; i < L; i++) {
            bool match = false;
            for (string& dig : digits) {
                if (dig[0] < s[i]) {
                    ans += pow(d, L - i - 1);
                } else if (dig[0] == s[i]) {
                    match = true;
                }
            }
            if (!match) return ans;
        }

        // n itself is valid
        return ans + 1;
    }
};
