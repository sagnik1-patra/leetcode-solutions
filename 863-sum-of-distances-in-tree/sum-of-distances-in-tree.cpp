class Solution {
public:
    vector<vector<int>> graph;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        res.resize(n, 0);
        count.resize(n, 1);

        // Build adjacency list
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // Step 1️⃣: Post-order DFS to compute subtree node counts and initial root (0) distance sum
        dfs1(0, -1);

        // Step 2️⃣: Pre-order DFS to propagate results to all nodes
        dfs2(0, -1, n);

        return res;
    }

    // Compute res[0] and subtree sizes
    void dfs1(int node, int parent) {
        for (int nei : graph[node]) {
            if (nei == parent) continue;
            dfs1(nei, node);
            count[node] += count[nei];
            res[node] += res[nei] + count[nei];
        }
    }

    // Use parent result to compute child result efficiently
    void dfs2(int node, int parent, int n) {
        for (int nei : graph[node]) {
            if (nei == parent) continue;
            res[nei] = res[node] - count[nei] + (n - count[nei]);
            dfs2(nei, node, n);
        }
    }
};