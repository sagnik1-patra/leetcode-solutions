class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        int targetMask = (1 << n) - 1;

        // queue: (node, mask)
        queue<pair<int,int>> q;

        // dist[node][mask] = steps
        vector<vector<int>> dist(n, vector<int>(1 << n, -1));

        // Initialize BFS from every node
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            dist[i][mask] = 0;
        }

        while (!q.empty()) {
            auto [node, mask] = q.front();
            q.pop();
            int steps = dist[node][mask];

            // If all nodes visited
            if (mask == targetMask) 
                return steps;

            // Explore neighbors
            for (int nei : graph[node]) {
                int newMask = mask | (1 << nei);

                if (dist[nei][newMask] == -1) {
                    dist[nei][newMask] = steps + 1;
                    q.push({nei, newMask});
                }
            }
        }

        return -1; // Should never happen for connected graph
    }
};
