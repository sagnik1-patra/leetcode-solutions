class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();           // number of rows
        int n = board[0].size();        // number of columns
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base case: word completely matched
        if (index == word.length()) return true;

        // Boundary checks and character mismatch
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || board[i][j] != word[index]) return false;

        // Save current char and mark as visited
        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        // Explore in all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        // Backtrack: restore original character
        board[i][j] = temp;

        return found;
    }
};
