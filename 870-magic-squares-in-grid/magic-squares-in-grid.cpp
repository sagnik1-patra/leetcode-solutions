class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        // Function to check if 3x3 grid is a magic square
        auto isMagic = [&](int r, int c) {
            vector<int> seen(10, 0);
            
            // Check all numbers are 1–9 and distinct
            for (int i = r; i < r + 3; i++) {
                for (int j = c; j < c + 3; j++) {
                    int val = grid[i][j];
                    if (val < 1 || val > 9 || seen[val]) return false;
                    seen[val] = 1;
                }
            }
            
            // Sum of rows, cols, and diagonals should all be 15
            int s = 15;
            for (int i = 0; i < 3; i++) {
                if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != s) return false;
                if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != s) return false;
            }
            
            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != s) return false;
            if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != s) return false;
            
            return true;
        };
        
        // Check all possible 3x3 subgrids
        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (isMagic(i, j)) count++;
            }
        }
        
        return count;
    }
};