class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> visited;
    int ans = 0;

    void dfs(int node, int time, int quality,
             int maxTime, vector<int>& values) {

        if (time > maxTime) {
            return;
        }

        if (node == 0) {
            ans = max(ans, quality);
        }

        for (auto [next, cost] : adj[node]) {

            if (time + cost > maxTime) {
                continue;
            }

            bool firstVisit = (visited[next] == 0);

            visited[next]++;

            dfs(next, time + cost,
                quality + (firstVisit ? values[next] : 0),
                maxTime, values);

            visited[next]--;
        }
    }

    int maximalPathQuality(vector<int>& values,
                           vector<vector<int>>& edges,
                           int maxTime) {

        int n = values.size();

        adj.assign(n, {});
        visited.assign(n, 0);
        ans = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        visited[0] = 1;

        dfs(0, 0, values[0], maxTime, values);

        return ans;
    }
};