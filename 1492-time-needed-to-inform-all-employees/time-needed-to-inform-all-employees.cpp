class Solution {
public:
    vector<vector<int>> adj;
    
    int dfs(int node, vector<int>& informTime) {
        int maxTime = 0;
        
        for (int child : adj[node]) {
            maxTime = max(maxTime, dfs(child, informTime));
        }
        
        return informTime[node] + maxTime;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        
        // build tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        
        return dfs(headID, informTime);
    }
};