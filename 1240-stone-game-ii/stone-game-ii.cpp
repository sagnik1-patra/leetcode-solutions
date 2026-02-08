class Solution {
public:
    int dp[101][101];
    vector<int> suffixSum;

    int solve(int i, int M, vector<int>& piles) {
        int n = piles.size();
        if (i >= n) return 0;
        if (dp[i][M] != -1) return dp[i][M];

        int best = 0;
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            best = max(best,
                       suffixSum[i] - solve(i + X, max(M, X), piles));
        }
        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));

        suffixSum.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return solve(0, 1, piles);
    }
};
