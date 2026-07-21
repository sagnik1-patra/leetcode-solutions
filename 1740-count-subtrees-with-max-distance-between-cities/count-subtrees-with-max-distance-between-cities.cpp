class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> ans(n-1, 0);
        
        int total = 1 << n;
        
        for (int mask = 1; mask < total; mask++) {
            vector<int> nodes;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) nodes.push_back(i);
            }
            
            if (nodes.size() <= 1) continue;
            
            // Check connectivity
            queue<int> q;
            unordered_set<int> visited;
            
            q.push(nodes[0]);
            visited.insert(nodes[0]);
            
            while (!q.empty()) {
                int u = q.front(); q.pop();
                
                for (int v : adj[u]) {
                    if ((mask & (1 << v)) && !visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            
            if (visited.size() != nodes.size()) continue;
            
            // Compute diameter
            
            auto bfs = [&](int start) {
                queue<pair<int,int>> q;
                vector<bool> vis(n, false);
                
                q.push({start, 0});
                vis[start] = true;
                
                int far = start, dist = 0;
                
                while (!q.empty()) {
                    auto [u, d] = q.front(); q.pop();
                    
                    if (d > dist) {
                        dist = d;
                        far = u;
                    }
                    
                    for (int v : adj[u]) {
                        if ((mask & (1 << v)) && !vis[v]) {
                            vis[v] = true;
                            q.push({v, d+1});
                        }
                    }
                }
                
                return pair<int,int>{far, dist};
            };
            
            auto [node, _] = bfs(nodes[0]);
            auto [_, diameter] = bfs(node);
            
            ans[diameter - 1]++;
        }
        
        return ans;
    }
};