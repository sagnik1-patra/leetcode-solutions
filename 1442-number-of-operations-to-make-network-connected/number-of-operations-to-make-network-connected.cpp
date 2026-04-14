class Solution {
public:
    vector<int> parent, rank;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa == pb) return;
        
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pb] < rank[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Not enough edges
        if (connections.size() < n - 1) return -1;
        
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) parent[i] = i;
        
        // Union all connections
        for (auto &c : connections) {
            unite(c[0], c[1]);
        }
        
        // Count components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) components++;
        }
        
        return components - 1;
    }
};