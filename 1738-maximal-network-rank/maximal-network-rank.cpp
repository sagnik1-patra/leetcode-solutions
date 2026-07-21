class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        unordered_set<string> connected;
        
        // Build degree + connection set
        for (auto &r : roads) {
            int u = r[0], v = r[1];
            degree[u]++;
            degree[v]++;
            
            connected.insert(to_string(u) + "," + to_string(v));
            connected.insert(to_string(v) + "," + to_string(u));
        }
        
        int maxRank = 0;
        
        // Check all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                
                if (connected.count(to_string(i) + "," + to_string(j))) {
                    rank--;
                }
                
                maxRank = max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};