class Solution {
public:
    int distinctSequences(int n) {

        const int MOD = 1e9 + 7;

        if (n == 1)
            return 6;

        vector<vector<int>> dp(7, vector<int>(7, 0));

        // Initialize sequences of length 2
        for (int a = 1; a <= 6; a++) {
            for (int b = 1; b <= 6; b++) {

                if (a != b && gcd(a, b) == 1) {
                    dp[a][b] = 1;
                }
            }
        }

        // Generate sequences of length 3 to n
        for (int len = 3; len <= n; len++) {

            vector<vector<int>> next(7, vector<int>(7, 0));

            for (int a = 1; a <= 6; a++) {
                for (int b = 1; b <= 6; b++) {
                    for (int c = 1; c <= 6; c++) {

                        if (c != a && c != b &&
                            gcd(b, c) == 1) {

                            next[b][c] = (
                                next[b][c] + dp[a][b]
                            ) % MOD;
                        }
                    }
                }
            }

            dp = next;
        }

        int ans = 0;

        for (int a = 1; a <= 6; a++) {
            for (int b = 1; b <= 6; b++) {

                ans = (ans + dp[a][b]) % MOD;
            }
        }

        return ans;
    }
};