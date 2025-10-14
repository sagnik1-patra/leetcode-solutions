class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        if (n == 0) return 0;

        long long dp1 = 1; // dp[i-1]
        long long dp2 = 1; // dp[i-2]

        // initialize first character
        if (s[0] == '0') dp1 = 0;
        else if (s[0] == '*') dp1 = 9;

        for (int i = 1; i < n; ++i) {
            long long curr = 0;

            // Single character decode
            if (s[i] == '*') curr += 9 * dp1;
            else if (s[i] != '0') curr += dp1;

            // Two character decode
            char c1 = s[i-1], c2 = s[i];
            if (c1 == '*' && c2 == '*') curr += 15 * dp2;
            else if (c1 == '*') {
                if (c2 <= '6') curr += 2 * dp2;
                else curr += dp2;
            }
            else if (c2 == '*') {
                if (c1 == '1') curr += 9 * dp2;
                else if (c1 == '2') curr += 6 * dp2;
            }
            else { // both digits
                int num = (c1 - '0') * 10 + (c2 - '0');
                if (num >= 10 && num <= 26) curr += dp2;
            }

            curr %= MOD;
            dp2 = dp1;
            dp1 = curr;
        }

        return dp1 % MOD;
    }
};
