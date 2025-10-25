class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        
        // DFS function to explore an island and return its area
        function<int(int,int)> dfs = [&](int i, int j) {
            // Check boundaries and water
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
                return 0;
            
            grid[i][j] = 0; // mark as visited
            int area = 1;   // current cell
            
            // Explore 4 directions
            area += dfs(i+1, j);
            area += dfs(i-1, j);
            area += dfs(i, j+1);
            area += dfs(i, j-1);
            
            return area;
        };
        
        // Iterate through the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j));
                }
            }
        }
        
        return maxArea;
    }
};
