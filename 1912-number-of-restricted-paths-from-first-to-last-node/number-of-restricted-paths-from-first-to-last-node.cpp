class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Dijkstra from node n
        vector<long long> dist(n + 1, LLONG_MAX);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[n] = 0;
        pq.push({0, n});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Sort nodes according to distance from n
        vector<int> nodes(n);

        for (int i = 0; i < n; i++)
            nodes[i] = i + 1;

        sort(nodes.begin(), nodes.end(),
             [&](int a, int b) {
                 return dist[a] < dist[b];
             });

        // dp[u] = number of restricted paths from u to n
        vector<long long> dp(n + 1, 0);

        dp[n] = 1;

        for (int u : nodes) {
            for (auto [v, w] : adj[u]) {

                // Restricted path condition
                if (dist[v] < dist[u]) {
                    dp[u] = (dp[u] + dp[v]) % MOD;
                }
            }
        }

        return dp[1];
    }
};