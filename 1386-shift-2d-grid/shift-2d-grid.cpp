class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;
        
        vector<int> flat;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                flat.push_back(grid[i][j]);
        
        vector<int> shifted(total);
        for(int i=0;i<total;i++)
            shifted[(i+k)%total] = flat[i];
        
        vector<vector<int>> new_grid(m, vector<int>(n));
        for(int i=0;i<total;i++)
            new_grid[i/n][i%n] = shifted[i];
        
        return new_grid;
    }
};