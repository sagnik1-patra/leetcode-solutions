class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candA, candB;
        
        // Step 1: Check if a node has two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // Node v has two parents
                candA = {parent[v], v};
                candB = edge;
                edge[1] = 0; // mark this edge invalid temporarily
            }
        }
        
        // Step 2: Union-Find to check for cycle
        for (int i = 0; i <= n; ++i) parent[i] = i;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue; // skip invalid edge
            
            int pu = find(parent, u);
            if (pu == v) {
                // Cycle found
                if (candA.empty())
                    return edge; // no two-parent issue
                else
                    return candA; // cycle caused by first parent edge
            }
            parent[v] = pu;
        }
        return candB; // if no cycle, remove second edge that caused two parents
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }
};