class Solution {
public:
    int total = 0;

    void backtrack(int n, int row,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {
        if (row == n) {
            total++; // Found one valid placement
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            backtrack(n, row + 1, cols, diag1, diag2);

            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        backtrack(n, 0, cols, diag1, diag2);
        return total;
    }
};
