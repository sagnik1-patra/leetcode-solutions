class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();

        // DFS function
        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O')
                return;
            board[r][c] = 'T';  // Temporarily mark as safe
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };

        // Step 1: Start DFS from all border 'O's
        for (int i = 0; i < rows; ++i) {
            dfs(i, 0);
            dfs(i, cols - 1);
        }
        for (int j = 0; j < cols; ++j) {
            dfs(0, j);
            dfs(rows - 1, j);
        }

        // Step 2: Flip enclosed 'O's to 'X' and 'T' back to 'O'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};
