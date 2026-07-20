class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Step 1: bounding boxes
        vector<int> minRow(61, m), maxRow(61, -1);
        vector<int> minCol(61, n), maxCol(61, -1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = grid[i][j];
                minRow[c] = min(minRow[c], i);
                maxRow[c] = max(maxRow[c], i);
                minCol[c] = min(minCol[c], j);
                maxCol[c] = max(maxCol[c], j);
            }
        }
        
        // Step 2: build graph
        vector<unordered_set<int>> graph(61);
        vector<int> indegree(61, 0);
        
        for (int c = 1; c <= 60; c++) {
            if (maxRow[c] == -1) continue;
            
            for (int i = minRow[c]; i <= maxRow[c]; i++) {
                for (int j = minCol[c]; j <= maxCol[c]; j++) {
                    int other = grid[i][j];
                    if (other != c) {
                        if (!graph[c].count(other)) {
                            graph[c].insert(other);
                            indegree[other]++;
                        }
                    }
                }
            }
        }
        
        // Step 3: topo sort
        queue<int> q;
        for (int i = 1; i <= 60; i++) {
            if (maxRow[i] != -1 && indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int visited = 0;
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            visited++;
            
            for (int nei : graph[cur]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        // count how many colors exist
        int totalColors = 0;
        for (int i = 1; i <= 60; i++) {
            if (maxRow[i] != -1) totalColors++;
        }
        
        return visited == totalColors;
    }
};