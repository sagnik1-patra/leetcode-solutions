class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        
        // build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<tuple<int,int,double>> q;
        vector<bool> visited(n + 1, false);
        
        q.push({1, 0, 1.0}); // node, time, probability
        visited[1] = true;
        
        while (!q.empty()) {
            auto [node, time, prob] = q.front();
            q.pop();
            
            // if reached target
            if (node == target) {
                // count unvisited neighbors
                int children = 0;
                for (int nei : adj[node]) {
                    if (!visited[nei]) children++;
                }
                
                // valid stopping condition
                if (time == t || children == 0) return prob;
                else return 0.0;
            }
            
            if (time >= t) continue;
            
            // count valid moves
            int children = 0;
            for (int nei : adj[node]) {
                if (!visited[nei]) children++;
            }
            
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, time + 1, prob / children});
                }
            }
        }
        
        return 0.0;
    }
};