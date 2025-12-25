class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> moves = {
            {4, 6},     // 0
            {6, 8},     // 1
            {7, 9},     // 2
            {4, 8},     // 3
            {0, 3, 9},  // 4
            {},         // 5
            {0, 1, 7},  // 6
            {2, 6},     // 7
            {1, 3},     // 8
            {2, 4}      // 9
        };

        vector<long long> dp(10, 1);  // dp for length = 1

        for (int step = 2; step <= n; step++) {
            vector<long long> next(10, 0);

            for (int d = 0; d <= 9; d++) {
                for (int prev : moves[d]) {
                    next[d] = (next[d] + dp[prev]) % MOD;
                }
            }

            dp = next;
        }

        long long ans = 0;
        for (long long x : dp) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};
