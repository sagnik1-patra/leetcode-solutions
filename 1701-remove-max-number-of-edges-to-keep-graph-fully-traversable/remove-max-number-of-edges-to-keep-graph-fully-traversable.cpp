class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        
        if (rank[pa] < rank[pb]) swap(pa, pb);
        parent[pb] = pa;
        if (rank[pa] == rank[pb]) rank[pa]++;
        
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int used = 0;
        
        // Step 1: Type 3 edges
        for (auto &e : edges) {
            if (e[0] == 3) {
                bool a = alice.unite(e[1], e[2]);
                bool b = bob.unite(e[1], e[2]);
                
                if (a || b) used++;
            }
        }
        
        // Step 2: Type 1 (Alice)
        for (auto &e : edges) {
            if (e[0] == 1) {
                if (alice.unite(e[1], e[2])) {
                    used++;
                }
            }
        }
        
        // Step 3: Type 2 (Bob)
        for (auto &e : edges) {
            if (e[0] == 2) {
                if (bob.unite(e[1], e[2])) {
                    used++;
                }
            }
        }
        
        // Check connectivity
        int compA = 0, compB = 0;
        for (int i = 1; i <= n; i++) {
            if (alice.find(i) == i) compA++;
            if (bob.find(i) == i) compB++;
        }
        
        if (compA > 1 || compB > 1) return -1;
        
        return edges.size() - used;
    }
};