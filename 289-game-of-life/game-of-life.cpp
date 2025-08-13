class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        static const int dr[8] = {-1,-1,-1,0,0,1,1,1};
        static const int dc[8] = {-1,0,1,-1,1,-1,0,1};

        // Use 2 bits per cell: bit0 = current state, bit1 = next state
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int live = 0;
                for (int k = 0; k < 8; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        live += (board[nr][nc] & 1); // count current state only
                    }
                }
                int cur = board[r][c] & 1;
                int next = 0;
                if (cur) next = (live == 2 || live == 3);   // survival
                else     next = (live == 3);                 // birth
                board[r][c] |= (next << 1);                  // write next to bit1
            }
        }
        // Shift next state into bit0
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                board[r][c] >>= 1;
    }
};
