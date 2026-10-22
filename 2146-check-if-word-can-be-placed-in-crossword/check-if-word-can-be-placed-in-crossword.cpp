
class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();

        // Check horizontal segments
        for (int i = 0; i < m; i++) {
            int j = 0;

            while (j < n) {
                if (board[i][j] == '#') {
                    j++;
                    continue;
                }

                int start = j;

                while (j < n && board[i][j] != '#') {
                    j++;
                }

                if (j - start != len) continue;

                bool forward = true;
                bool backward = true;

                for (int k = 0; k < len; k++) {
                    char c = board[i][start + k];

                    if (c != ' ' && c != word[k])
                        forward = false;

                    if (c != ' ' && c != word[len - 1 - k])
                        backward = false;
                }

                if (forward || backward) return true;
            }
        }

        // Check vertical segments
        for (int j = 0; j < n; j++) {
            int i = 0;

            while (i < m) {
                if (board[i][j] == '#') {
                    i++;
                    continue;
                }

                int start = i;

                while (i < m && board[i][j] != '#') {
                    i++;
                }

                if (i - start != len) continue;

                bool forward = true;
                bool backward = true;

                for (int k = 0; k < len; k++) {
                    char c = board[start + k][j];

                    if (c != ' ' && c != word[k])
                        forward = false;

                    if (c != ' ' && c != word[len - 1 - k])
                        backward = false;
                }

                if (forward || backward) return true;
            }
        }

        return false;
    }
};
