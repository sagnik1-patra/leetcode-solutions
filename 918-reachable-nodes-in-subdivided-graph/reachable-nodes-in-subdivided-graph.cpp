class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Build adjacency list
        vector<vector<pair<int,int>>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            graph[u].push_back({v, cnt + 1});
            graph[v].push_back({u, cnt + 1});
        }

        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        long long ans = 0;

        // Count reachable original nodes
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                ans++;
        }

        // Count reachable subdivided nodes
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long long remU = max(0LL, maxMoves - dist[u]);
            long long remV = max(0LL, maxMoves - dist[v]);
            ans += min((long long)cnt, remU + remV);
        }

        return ans;
    }
};
