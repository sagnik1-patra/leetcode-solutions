#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> memo;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memo.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }

    int dfs(int i, int j, int move) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1; // out of boundary
        if (move == 0) return 0; // no moves left
        if (memo[i][j][move] != -1) return memo[i][j][move];

        long long paths = 0;
        paths += dfs(i - 1, j, move - 1);
        paths += dfs(i + 1, j, move - 1);
        paths += dfs(i, j - 1, move - 1);
        paths += dfs(i, j + 1, move - 1);

        return memo[i][j][move] = paths % MOD;
    }
};