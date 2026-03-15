class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int r, int c){
        
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        
        int gold = grid[r][c];
        grid[r][c] = 0; // mark visited
        
        int best = 0;
        
        best = max(best, dfs(grid, r+1, c));
        best = max(best, dfs(grid, r-1, c));
        best = max(best, dfs(grid, r, c+1));
        best = max(best, dfs(grid, r, c-1));
        
        grid[r][c] = gold; // backtrack
        
        return gold + best;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] > 0){
                    ans = max(ans, dfs(grid,i,j));
                }
            }
        }
        
        return ans;
    }
};