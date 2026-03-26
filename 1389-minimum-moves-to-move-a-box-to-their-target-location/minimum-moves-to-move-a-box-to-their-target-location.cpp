class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        pair<int,int> player, box, target;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='S') player = {i,j};
                if(grid[i][j]=='B') box = {i,j};
                if(grid[i][j]=='T') target = {i,j};
            }
        }
        
        // Directions
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        
        // BFS queue: box_x, box_y, player_x, player_y, pushes
        queue<tuple<int,int,int,int,int>> q;
        q.push({box.first, box.second, player.first, player.second, 0});
        
        set<tuple<int,int,int,int>> visited;
        visited.insert({box.first, box.second, player.first, player.second});
        
        auto canReach = [&](pair<int,int> start, pair<int,int> end, pair<int,int> boxPos){
            // BFS to check if player can go from start to end without crossing box
            queue<pair<int,int>> qq;
            qq.push(start);
            vector<vector<bool>> vis(m, vector<bool>(n,false));
            vis[start.first][start.second]=true;
            while(!qq.empty()){
                auto [x,y]=qq.front(); qq.pop();
                if(x==end.first && y==end.second) return true;
                for(auto [dx,dy]: dirs){
                    int nx=x+dx, ny=y+dy;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]!='#' && !(nx==boxPos.first && ny==boxPos.second)){
                        vis[nx][ny]=true;
                        qq.push({nx,ny});
                    }
                }
            }
            return false;
        };
        
        while(!q.empty()){
            auto [bx,by,px,py,pushes]=q.front(); q.pop();
            if(bx==target.first && by==target.second) return pushes;
            
            for(auto [dx,dy]: dirs){
                int nbx=bx+dx, nby=by+dy; // new box position
                int px_needed=bx-dx, py_needed=by-dy; // player must be here to push
                
                if(nbx<0||nbx>=m||nby<0||nby>=n) continue;
                if(grid[nbx][nby]=='#') continue;
                if(px_needed<0||px_needed>=m||py_needed<0||py_needed>=n) continue;
                if(grid[px_needed][py_needed]=='#') continue;
                
                if(!canReach({px,py},{px_needed,py_needed},{bx,by})) continue;
                
                auto state = make_tuple(nbx,nby,bx,by);
                if(visited.count(state)) continue;
                
                visited.insert(state);
                q.push({nbx,nby,bx,by,pushes+1});
            }
        }
        
        return -1;
    }
};