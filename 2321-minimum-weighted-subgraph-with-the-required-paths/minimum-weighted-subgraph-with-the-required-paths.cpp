
class Solution {
public:
    using ll = long long;
    using P = pair<ll, int>;

    vector<ll> dijkstra(int src,
                        vector<vector<pair<int,int>>>& adj) {
        int n = adj.size();
        const ll INF = LLONG_MAX / 4;

        vector<ll> dist(n, INF);
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges,
                            int src1, int src2, int dest) {

        vector<vector<pair<int,int>>> adj(n), rev(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            adj[u].push_back({v, w});
            rev[v].push_back({u, w});
        }

        vector<ll> d1 = dijkstra(src1, adj);
        vector<ll> d2 = dijkstra(src2, adj);
        vector<ll> d3 = dijkstra(dest, rev);

        const ll INF = LLONG_MAX / 4;
        ll ans = INF;

        for (int i = 0; i < n; i++) {
            if (d1[i] == INF || d2[i] == INF || d3[i] == INF)
                continue;

            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }

        return ans == INF ? -1 : ans;
    }
};
