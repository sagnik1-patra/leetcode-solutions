
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> row(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> col(m + 1, vector<long long>(n, 0));

        // Calculate row prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
            }
        }

        // Calculate column prefix sums
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        // Check squares from largest to smallest
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    long long target = row[i][j + k] - row[i][j];
                    bool valid = true;

                    // Check all rows
                    for (int r = i; r < i + k; r++) {
                        if (row[r][j + k] - row[r][j] != target) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid) continue;

                    // Check all columns
                    for (int c = j; c < j + k; c++) {
                        if (col[i + k][c] - col[i][c] != target) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid) continue;

                    // Check both diagonals
                    long long d1 = 0, d2 = 0;

                    for (int x = 0; x < k; x++) {
                        d1 += grid[i + x][j + x];
                        d2 += grid[i + x][j + k - 1 - x];
                    }

                    if (d1 == target && d2 == target) {
                        return k;
                    }
                }
            }
        }

        return 1;
    }
};
