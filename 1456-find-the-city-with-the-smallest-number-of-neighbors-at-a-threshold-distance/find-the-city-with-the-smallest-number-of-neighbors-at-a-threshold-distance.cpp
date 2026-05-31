class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // Step 1: initialize
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Step 2: Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        // Step 3: find city with minimum reachable nodes
        int result = -1;
        int minCount = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            
            // tie-breaking → choose larger index
            if (count <= minCount) {
                minCount = count;
                result = i;
            }
        }
        
        return result;
    }
};