class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        
        // Add all land cells to queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        // If no land OR all land
        if (q.empty() || q.size() == n * n)
            return -1;
        
        int distance = -1;
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        while (!q.empty()) {
            int size = q.size();
            distance++;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d];
                    int ny = y + dirs[d+1];
                    
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n 
                        && grid[nx][ny] == 0) {
                        
                        grid[nx][ny] = 1; // mark visited
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return distance;
    }
};