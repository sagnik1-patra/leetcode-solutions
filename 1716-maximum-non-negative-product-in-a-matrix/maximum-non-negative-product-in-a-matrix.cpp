class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        vector<vector<long long>> mx(m, vector<long long>(n));
        vector<vector<long long>> mn(m, vector<long long>(n));
        
        mx[0][0] = mn[0][0] = grid[0][0];
        
        // first row
        for (int j = 1; j < n; j++) {
            mx[0][j] = mn[0][j] = mx[0][j-1] * grid[0][j];
        }
        
        // first column
        for (int i = 1; i < m; i++) {
            mx[i][0] = mn[i][0] = mx[i-1][0] * grid[i][0];
        }
        
        // fill DP
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long a = grid[i][j] * mx[i-1][j];
                long long b = grid[i][j] * mn[i-1][j];
                long long c = grid[i][j] * mx[i][j-1];
                long long d = grid[i][j] * mn[i][j-1];
                
                mx[i][j] = max({a, b, c, d});
                mn[i][j] = min({a, b, c, d});
            }
        }
        
        long long res = mx[m-1][n-1];
        
        if (res < 0) return -1;
        return res % MOD;
    }
};