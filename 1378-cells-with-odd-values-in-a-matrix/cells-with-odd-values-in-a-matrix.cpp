class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0), col(n, 0);
        
        // Count increments
        for (auto &idx : indices) {
            row[idx[0]]++;
            col[idx[1]]++;
        }
        
        int oddRows = 0, oddCols = 0;
        
        // Count odd rows
        for (int r : row)
            if (r % 2) oddRows++;
        
        // Count odd columns
        for (int c : col)
            if (c % 2) oddCols++;
        
        int evenRows = m - oddRows;
        int evenCols = n - oddCols;
        
        return oddRows * evenCols + evenRows * oddCols;
    }
};