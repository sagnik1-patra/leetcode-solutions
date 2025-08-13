class NumMatrix {
public:
    // ps[r+1][c+1] = sum of submatrix (0,0) .. (r,c)
    vector<vector<int>> ps;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        ps.assign(m + 1, vector<int>(n + 1, 0));
        for (int r = 1; r <= m; ++r) {
            int rowsum = 0;
            for (int c = 1; c <= n; ++c) {
                rowsum += matrix[r - 1][c - 1];
                ps[r][c] = ps[r - 1][c] + rowsum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Inclusion–exclusion on the prefix-sum table
        int R1 = row1, C1 = col1, R2 = row2, C2 = col2;
        return ps[R2 + 1][C2 + 1]
             - ps[R1][C2 + 1]
             - ps[R2 + 1][C1]
             + ps[R1][C1];
    }
};
