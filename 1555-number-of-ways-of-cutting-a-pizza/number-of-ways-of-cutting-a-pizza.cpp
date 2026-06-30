class Solution {
public:
    int MOD = 1e9 + 7;
    int rows, cols;
    vector<vector<int>> pre;
    int dp[51][51][11];

    // check if submatrix has apple
    bool hasApple(int r1, int c1, int r2, int c2) {
        return pre[r1][c1] - pre[r2][c1] - pre[r1][c2] + pre[r2][c2] > 0;
    }

    int solve(int r, int c, int cuts) {
        if (pre[r][c] == 0) return 0; // no apple
        if (cuts == 0) return 1;

        if (dp[r][c][cuts] != -1) return dp[r][c][cuts];

        int ways = 0;

        // horizontal cuts
        for (int nr = r + 1; nr < rows; nr++) {
            if (hasApple(r, c, nr, cols)) {
                ways = (ways + solve(nr, c, cuts - 1)) % MOD;
            }
        }

        // vertical cuts
        for (int nc = c + 1; nc < cols; nc++) {
            if (hasApple(r, c, rows, nc)) {
                ways = (ways + solve(r, nc, cuts - 1)) % MOD;
            }
        }

        return dp[r][c][cuts] = ways;
    }

    int ways(vector<string>& pizza, int k) {
        rows = pizza.size();
        cols = pizza[0].size();

        pre.assign(rows + 1, vector<int>(cols + 1, 0));

        // build prefix sum (bottom-right based)
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                pre[i][j] = (pizza[i][j] == 'A') 
                          + pre[i+1][j] 
                          + pre[i][j+1] 
                          - pre[i+1][j+1];
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, k - 1);
    }
};