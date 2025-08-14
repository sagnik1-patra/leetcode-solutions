class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> deg(n, 0);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            ++deg[a]; ++deg[b];
        }

        // Start from all leaves (degree 1) and trim layer by layer
        queue<int> q;
        for (int i = 0; i < n; ++i) if (deg[i] == 1) q.push(i);

        int remaining = n;
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;
            while (sz--) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (--deg[v] == 1) q.push(v);
                }
            }
        }

        vector<int> centers;
        while (!q.empty()) { centers.push_back(q.front()); q.pop(); }
        return centers; // 1 or 2 centers
    }
};
