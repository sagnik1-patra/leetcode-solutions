class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;

        // Count X and O
        for (auto &row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                else if (c == 'O') oCount++;
            }
        }

        // Rule 1: X always goes first, so xCount >= oCount
        if (oCount > xCount) return false;

        // Rule 2: X cannot play more than one extra move
        if (xCount - oCount > 1) return false;

        // Helper lambda to check win
        auto win = [&](char p) {
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true; // row
                if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true; // column
            }
            if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true; // diag
            if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true; // anti-diag
            return false;
        };

        bool xWin = win('X');
        bool oWin = win('O');

        // Rule 3: Both players can't win
        if (xWin && oWin) return false;

        // Rule 4: If X wins, must have one more move than O
        if (xWin && xCount != oCount + 1) return false;

        // Rule 5: If O wins, must have same number of moves as X
        if (oWin && xCount != oCount) return false;

        // Otherwise valid
        return true;
    }
};