class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = 0, c = 0;

        // Find the rook
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }

        int captures = 0;
        vector<pair<int,int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        // Check all 4 directions
        for (auto [dr, dc] : directions) {
            int x = r + dr;
            int y = c + dc;

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 'B') break;
                if (board[x][y] == 'p') {
                    captures++;
                    break;
                }
                x += dr;
                y += dc;
            }
        }

        return captures;
    }
};
