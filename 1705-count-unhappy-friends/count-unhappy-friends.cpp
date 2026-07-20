class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        
        // Step 1: rank matrix
        vector<vector<int>> rank(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < preferences[i].size(); j++) {
                rank[i][preferences[i][j]] = j;
            }
        }
        
        // Step 2: partner mapping
        vector<int> partner(n);
        for (auto &p : pairs) {
            partner[p[0]] = p[1];
            partner[p[1]] = p[0];
        }
        
        int unhappy = 0;
        
        // Step 3: check each person
        for (int x = 0; x < n; x++) {
            int y = partner[x];
            
            // check all u preferred over y
            for (int i = 0; preferences[x][i] != y; i++) {
                int u = preferences[x][i];
                int v = partner[u];
                
                // if u prefers x over v
                if (rank[u][x] < rank[u][v]) {
                    unhappy++;
                    break;
                }
            }
        }
        
        return unhappy;
    }
};