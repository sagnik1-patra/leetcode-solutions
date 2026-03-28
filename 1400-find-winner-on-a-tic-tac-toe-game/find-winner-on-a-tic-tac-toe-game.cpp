class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3, 0), cols(3, 0);
        int diag = 0, antiDiag = 0;

        int player = 1; // A = +1, B = -1

        for (auto &move : moves) {
            int r = move[0];
            int c = move[1];

            rows[r] += player;
            cols[c] += player;

            if (r == c)
                diag += player;

            if (r + c == 2)
                antiDiag += player;

            // Check win condition
            if (abs(rows[r]) == 3 || abs(cols[c]) == 3 || 
                abs(diag) == 3 || abs(antiDiag) == 3) {
                
                return player == 1 ? "A" : "B";
            }

            player *= -1; // switch player
        }

        // If all moves played
        if (moves.size() == 9)
            return "Draw";

        return "Pending";
    }
};