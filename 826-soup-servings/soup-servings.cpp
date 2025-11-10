class Solution {
public:
    double dp[200][200]; // memoization table

    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5; // both empty
        if (a <= 0) return 1.0;           // A empty first
        if (b <= 0) return 0.0;           // B empty first

        if (dp[a][b] > 0) return dp[a][b];

        dp[a][b] = 0.25 * (
            solve(a - 4, b) +
            solve(a - 3, b - 1) +
            solve(a - 2, b - 2) +
            solve(a - 1, b - 3)
        );
        return dp[a][b];
    }

    double soupServings(int n) {
        if (n > 4800) return 1.0; // Optimization: for large n, probability → 1

        // Scale n to units of 25mL for smaller DP state
        int m = ceil(n / 25.0);
        memset(dp, 0, sizeof(dp));

        return solve(m, m);
    }
};