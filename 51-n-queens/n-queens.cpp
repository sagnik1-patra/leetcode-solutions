class Solution {
public:
    vector<vector<string>> result;

    void solve(int n, int row, vector<string>& board,
               vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue; // Position is under attack

            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            solve(n, row + 1, board, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        solve(n, 0, board, cols, diag1, diag2);
        return result;
    }
};
