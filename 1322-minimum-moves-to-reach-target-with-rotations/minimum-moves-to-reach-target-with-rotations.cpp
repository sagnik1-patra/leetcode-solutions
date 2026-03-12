class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<tuple<int,int,int>> q;
        set<tuple<int,int,int>> vis;

        q.push({0,0,0}); // r,c,orientation
        vis.insert({0,0,0});

        int steps = 0;

        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto [r,c,dir] = q.front();
                q.pop();

                if(r == n-1 && c == n-2 && dir == 0)
                    return steps;

                if(dir == 0){ // horizontal
                    
                    if(c+2 < n && grid[r][c+2] == 0){
                        if(!vis.count({r,c+1,0})){
                            vis.insert({r,c+1,0});
                            q.push({r,c+1,0});
                        }
                    }

                    if(r+1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0){
                        
                        if(!vis.count({r+1,c,0})){
                            vis.insert({r+1,c,0});
                            q.push({r+1,c,0});
                        }

                        if(!vis.count({r,c,1})){
                            vis.insert({r,c,1});
                            q.push({r,c,1});
                        }
                    }
                }
                else{ // vertical
                    
                    if(r+2 < n && grid[r+2][c] == 0){
                        if(!vis.count({r+1,c,1})){
                            vis.insert({r+1,c,1});
                            q.push({r+1,c,1});
                        }
                    }

                    if(c+1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0){
                        
                        if(!vis.count({r,c+1,1})){
                            vis.insert({r,c+1,1});
                            q.push({r,c+1,1});
                        }

                        if(!vis.count({r,c,0})){
                            vis.insert({r,c,0});
                            q.push({r,c,0});
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};