class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},
                                {1,1},{1,-1},{-1,1},{-1,-1}};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int r = click[0], c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(board, r, c);
        return board;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') return;

        int mines = countMines(board, r, c);
        if (mines > 0) {
            board[r][c] = '0' + mines;
        } else {
            board[r][c] = 'B';
            for (auto& d : dirs) {
                dfs(board, r + d[0], c + d[1]);
            }
        }
    }

    int countMines(vector<vector<char>>& board, int r, int c) {
        int count = 0;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                count++;
            }
        }
        return count;
    }
};