class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto &t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        using pii = pair<int,int>; // {time, node}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if (time > dist[node]) continue; // skip outdated entry

            for (auto &[nei, wt] : graph[node]) {
                if (dist[nei] > time + wt) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
